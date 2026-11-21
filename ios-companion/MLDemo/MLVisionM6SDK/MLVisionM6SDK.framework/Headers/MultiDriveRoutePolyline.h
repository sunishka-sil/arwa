//
//  MultiDriveRoutePolyline.h
//  AMapNaviKit
//
//  Created by whj on 2019/3/4.
//  Copyright © 2019 Amap. All rights reserved.
//

#import <AMapNaviKit/MAMapKit.h>


@interface MultiDriveRoutePolyline : MAMultiPolyline

@property (nonatomic, strong) NSArray<UIImage *> *polylineTextureImages;

@property (nonatomic, strong) NSArray<UIImage *> *polylineTextureImagesSeleted;

@property (nonatomic, assign) NSInteger routeID;

@end
