//
//  DEDigitEntryStrings.h
//  SquareReader
//
//  Created by Andrew Klinker on 3/2/21.
//


@interface DEDigitEntryStrings : NSObject

- (nonnull instancetype)initWithTitle:(nonnull NSString *)title
                            clearText:(nonnull NSString *)clearText
                         buttonTitles:(nonnull NSArray<NSString *> *)buttonTitles
                  notEnoughDigitsText:(nonnull NSString *)notEnoughDigitsText
               cancelTransactionTitle:(nonnull NSString *)cancelTransactionTitle
                cancelTransactionText:(nonnull NSString *)cancelTransactionText
                             backText:(nonnull NSString *)backText
                 incorrectDigitsTitle:(nonnull NSString *)incorrectDigitsTitle
                      lastAttemptText:(nonnull NSString *)lastAttemptText
                         tryAgainText:(nonnull NSString *)tryAgainText;

// DEEnterDigitsScreen
@property (nonatomic, copy, nonnull, readonly) NSString *title;
@property (nonatomic, copy, nonnull, readonly) NSString *clearText;
@property (nonatomic, copy, nonnull, readonly) NSArray<NSString *> *buttonTitles;
@property (nonatomic, copy, nonnull, readonly) NSString *notEnoughDigitsText;

// DECancelTransactionScreen
@property (nonatomic, copy, nonnull, readonly) NSString *cancelTransactionTitle;
@property (nonatomic, copy, nonnull, readonly) NSString *cancelTransactionText;
@property (nonatomic, copy, nonnull, readonly) NSString *backText;

// DEIncorrectDigitsScreen
@property (nonatomic, copy, nonnull, readonly) NSString *incorrectDigitsTitle;
@property (nonatomic, copy, nonnull, readonly) NSString *lastAttemptText;
@property (nonatomic, copy, nonnull, readonly) NSString *tryAgainText;

@end
