//
//  DEDigitEntryGlyphs.h
//  SquareReader
//
//  Created by Andrew Klinker on 3/2/21.
//


@interface DEDigitEntryGlyphs : NSObject

- (nonnull instancetype)initWithCancelGlyph:(nonnull UIImage *)cancelGlyph
                                submitGlyph:(nonnull UIImage *)submitGlyph
                                   dotGlyph:(nonnull UIImage *)dotGlyph;

@property (nonatomic, copy, nonnull, readonly) UIImage *cancelGlyph;
@property (nonatomic, copy, nonnull, readonly) UIImage *submitGlyph;
@property (nonatomic, copy, nonnull, readonly) UIImage *dotGlyph;

@end
