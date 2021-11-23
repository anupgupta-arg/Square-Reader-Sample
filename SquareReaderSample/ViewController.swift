//
//  ViewController.swift
//  SquareReaderSample
//
//  Created by Anup Gupta on 16/11/21.
//

import UIKit
//import SquareReaderSDK
import Alamofire
import CoreLocation
import AVFoundation

class ViewController: UIViewController {
    
    private lazy var locationManager = CLLocationManager()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        locationButtonTapped()
        microphoneButtonTapped()
        getAuthorizationCode()
        // Do any additional setup after loading the view.
    }
    
    // MARK: - Private Methods
    private func openSettings() {
        if let url = URL(string: UIApplication.openSettingsURLString) {
            UIApplication.shared.open(url, options: [:], completionHandler: nil)
        }
    }
}


extension ViewController {
    
    private func getAuthorizationCode(){
        
        let accessToken = "EAAAEHi0L_M1570YBDXChiQOPrroDQzV2gKFXXY3TATpwLkVUYxUmExXITDYXNx-"
        let accessTokenUrl = "https://connect.squareupsandbox.com/mobile/authorization-code"
        let locationID = "EE06GHZ87X36F"
        
        let headers: HTTPHeaders = [
            "Authorization" : "Bearer \(accessToken)",
            "Content-Type": "application/json",
            
        ]
        let param = ["location_id": locationID]
        
        AF.request(accessTokenUrl, method: .post, parameters: param, encoding: JSONEncoding.default, headers: headers).responseJSON  { [self] response in
            print(response)
            switch response.result {
            case .success(let responseData):
                print("responseData",responseData)
                do {
                    let decoder = JSONDecoder();
                    let authorization = try decoder.decode(Authorization.self, from: responseData as! Data);
                    let authorizationCode =  authorization.authorizationCode;
//                    authorize(withCode: authorizationCode);
                }catch let error{
                    
                    print("ERRROR >>", error);
                    //                                        isSuccess(false, nil)
                }
            case .failure(let error):
                
                print("error--->",error)
            }
        }
    }
}

// MARK: - Permission for Location
extension ViewController :CLLocationManagerDelegate{
    
    @objc private func locationButtonTapped() {
        switch CLLocationManager.authorizationStatus() {
        case .denied, .restricted:
            openSettings()
        case .notDetermined:
            requestLocationAccess()
        case .authorizedAlways, .authorizedWhenInUse:
            return
        @unknown default:
            print(" @unknown default")
        }
    }
    
    private func requestLocationAccess() {
        locationManager.delegate = self
        locationManager.requestWhenInUseAuthorization()
    }
    
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        updateLocationButton()
        print(">>>>> locationManager permission granted")
        //        if PermissionsViewController.areRequiredPermissionsGranted {
        //            delegate?.permissionsViewControllerDidObtainRequiredPermissions(self)
        //        }
    }
    
    @objc private func updateLocationButton() {
        let title: String
        let isEnabled: Bool
        
        switch CLLocationManager.authorizationStatus() {
        case .denied, .restricted:
            title = "Enable Location in Settings"
            isEnabled = true
        case .authorizedAlways, .authorizedWhenInUse:
            title = "Location Granted"
            isEnabled = false
        case .notDetermined:
            title = "Enable Location Access"
            isEnabled = true
        @unknown default:
            print(" @unknown default")
        }
        
        //        locationButton.setTitle(title, for: [])
        //        locationButton.isEnabled = isEnabled
    }
}

// MARK: - Permission for Microphone Access
extension ViewController {
    
    @objc private func microphoneButtonTapped() {
        switch AVAudioSession.sharedInstance().recordPermission {
        case .denied:
            openSettings()
        case .undetermined:
            requestMicrophoneAccess()
        case .granted:
            return
        @unknown default:
            print(" @unknown default")
        }
    }
    
    private func requestMicrophoneAccess() {
        AVAudioSession.sharedInstance().requestRecordPermission { _ in
            DispatchQueue.main.async {
                self.updateMicrophoneButton()
                
                print(">>>>> requestMicrophoneAccess permission granted")
            }
        }
    }
    
    @objc private func updateMicrophoneButton() {
        let title: String
        let isEnabled: Bool
        
        switch AVAudioSession.sharedInstance().recordPermission {
        case .denied:
            title = "Enable Microphone in Settings"
            isEnabled = true
        case .granted:
            title = "Microphone Enabled"
            isEnabled = false
        case .undetermined:
            title = "Enable Microphone Access"
            isEnabled = true
        @unknown default:
            print(" @unknown default")
        }
        
        //        microphoneButton.setTitle(title, for: [])
        //        microphoneButton.isEnabled = isEnabled
    }
}

// MARK: - Authorize Access
//extension ViewController {
//
//    func authorize(withCode code: String) {
//        // Authorize Reader SDK
//        SQRDReaderSDK.shared.authorize(withCode: code) { location, error in
//            if let authError = error as? SQRDAuthorizationError {
//                self.handleError(authError)
//            } else if let location = location {
//                self.handleSuccess(with: location)
//            }
//        }
//    }
//
//    func handleError(_ error: SQRDAuthorizationError) {
//        guard let debugCode = error.userInfo[SQRDErrorDebugCodeKey] as? String,
//              let debugMessage = error.userInfo[SQRDErrorDebugMessageKey] as? String else { return }
//
//        // Print the debug code and message
//        print(debugCode)
//        print(debugMessage)
//
//        // Show the error
//        let alertController = UIAlertController(title: "Authorization Error", message: error.localizedDescription, preferredStyle: .alert)
//        alertController.addAction(UIAlertAction(title: "OK", style: .cancel, handler: { (_) in
//            // Go back to the start authorization view controller
//            //            self.delegate?.authorizeViewControllerDidFailAuthorization(self)
//
//            print("Authorization Error")
//        }))
//        present(alertController, animated: true, completion: {
//            // Provide haptic feedback
//            self.triggerHaptic(.error)
//        })
//    }
//
//    func handleSuccess(with location: SQRDLocation) {
//        triggerHaptic(.success)
//
//        // Print the location name
//        print("Authorized Reader SDK to take payments for \(location.name)")
//
//        // Push to the pay view controller
//        //        self.delegate?.authorizeViewControllerDidCompleteAuthorization(self)
//    }
//
//    func triggerHaptic(_ type: UINotificationFeedbackGenerator.FeedbackType) {
//        let generator = UINotificationFeedbackGenerator()
//        generator.notificationOccurred(type)
//    }
//}



struct Authorization: Codable {
    let authorizationCode: String
    let expiresAt: Date
    
    enum CodingKeys: String, CodingKey {
        case authorizationCode = "authorization_code"
        case expiresAt = "expires_at"
    }
}
