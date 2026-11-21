//
//  SelectableTrafficOverlay.h
//  MultiRoutePlan
//
//  Created by AutoNavi on 11/3/16.
//  Copyright © 2016 AutoNavi. All rights reserved.
//

#import <AMapNaviKit/AMapNaviKit.h>

@interface SelectableTrafficOverlay : MAMultiPolyline

@property (nonatomic, assign) NSInteger routeID;

@property (nonatomic, assign) BOOL selected;
@property (nonatomic, assign) CGFloat polylineWidth;

@property (nonatomic, copy) NSArray<UIColor *> *polylineStrokeColors;
@property (nonatomic, copy) NSArray<UIImage *> *polylineTextureImages;

@end
