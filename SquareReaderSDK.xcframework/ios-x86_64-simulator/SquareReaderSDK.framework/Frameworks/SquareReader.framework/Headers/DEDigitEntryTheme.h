//
//  DEDigitEntryTheme.h
//  SquareReader
//
//  Created by Andrew Klinker on 3/2/21.
//


@interface DEDigitEntryTheme : NSObject

- (nonnull instancetype)initWithBackgroundColor:(nonnull UIColor *)backgroundColor
                               digitButtonColor:(nonnull UIColor *)digitButtonColor
                              cancelButtonColor:(nonnull UIColor *)cancelButtonColor
                               clearButtonColor:(nonnull UIColor *)clearButtonColor
                              submitButtonColor:(nonnull UIColor *)submitButtonColor
                                backButtonColor:(nonnull UIColor *)backButtonColor
                   cancelTransactionButtonColor:(nonnull UIColor *)cancelTransactionButtonColor
                            tryAgainButtonColor:(nonnull UIColor *)tryAgainButtonColor
                                       dotColor:(nonnull UIColor *)dotColor
                                 titleTextColor:(nonnull UIColor *)titleTextColor
                              cardInfoTextColor:(nonnull UIColor *)cardInfoTextColor
                       notEnoughDigitsTextColor:(nonnull UIColor *)notEnoughDigitsTextColor
                           digitButtonTextColor:(nonnull UIColor *)digitButtonTextColor
                            backButtonTextColor:(nonnull UIColor *)backButtonTextColor
               cancelTransactionButtonTextColor:(nonnull UIColor *)cancelTransactionButtonTextColor
                           lastAttemptTextColor:(nonnull UIColor *)lastAttemptTextColor
                        tryAgainButtonTextColor:(nonnull UIColor *)tryAgainButtonTextColor
                                      titleFont:(nonnull UIFont *)titleFont
                                   cardInfoFont:(nonnull UIFont *)cardInfoFont
                            notEnoughDigitsFont:(nonnull UIFont *)notEnoughDigitsFont
                                digitButtonFont:(nonnull UIFont *)digitButtonFont
                                 backButtonFont:(nonnull UIFont *)backButtonFont
                    cancelTransactionButtonFont:(nonnull UIFont *)cancelTransactionButtonFont
                                lastAttemptFont:(nonnull UIFont *)lastAttemptFont
                             tryAgainButtonFont:(nonnull UIFont *)tryAgainButtonFont;

// Element Colors
@property (nonatomic, copy, nonnull, readonly) UIColor *backgroundColor;
@property (nonatomic, copy, nonnull, readonly) UIColor *digitButtonColor;
@property (nonatomic, copy, nonnull, readonly) UIColor *cancelButtonColor;
@property (nonatomic, copy, nonnull, readonly) UIColor *clearButtonColor;
@property (nonatomic, copy, nonnull, readonly) UIColor *submitButtonColor;
@property (nonatomic, copy, nonnull, readonly) UIColor *backButtonColor;
@property (nonatomic, copy, nonnull, readonly) UIColor *cancelTransactionButtonColor;
@property (nonatomic, copy, nonnull, readonly) UIColor *tryAgainButtonColor;
@property (nonatomic, copy, nonnull, readonly) UIColor *dotColor;

// Text Colors
@property (nonatomic, copy, nonnull, readonly) UIColor *titleTextColor;
@property (nonatomic, copy, nonnull, readonly) UIColor *cardInfoTextColor;
@property (nonatomic, copy, nonnull, readonly) UIColor *notEnoughDigitsTextColor;
@property (nonatomic, copy, nonnull, readonly) UIColor *digitButtonTextColor;
@property (nonatomic, copy, nonnull, readonly) UIColor *backButtonTextColor;
@property (nonatomic, copy, nonnull, readonly) UIColor *cancelTransactionButtonTextColor;
@property (nonatomic, copy, nonnull, readonly) UIColor *lastAttemptTextColor;
@property (nonatomic, copy, nonnull, readonly) UIColor *tryAgainButtonTextColor;

// Fonts
@property (nonatomic, copy, nonnull, readonly) UIFont *titleFont;
@property (nonatomic, copy, nonnull, readonly) UIFont *cardInfoFont;
@property (nonatomic, copy, nonnull, readonly) UIFont *notEnoughDigitsFont;
@property (nonatomic, copy, nonnull, readonly) UIFont *digitButtonFont;
@property (nonatomic, copy, nonnull, readonly) UIFont *backButtonFont;
@property (nonatomic, copy, nonnull, readonly) UIFont *cancelTransactionButtonFont;
@property (nonatomic, copy, nonnull, readonly) UIFont *lastAttemptFont;
@property (nonatomic, copy, nonnull, readonly) UIFont *tryAgainButtonFont;

@end
