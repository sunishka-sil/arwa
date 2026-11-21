//
//  MLColoedRouteManager.h
//  xr_ios
//
//  Created by lijuan on 11/13/24.
//

#import <Foundation/Foundation.h>
#import <AMapNaviKit/MAMapKit.h>
#import <AMapNaviKit/AMapNaviKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface MLRouteInfoModel : NSObject

@property (nonatomic, assign) NSInteger routeID;
@property (nonatomic, assign) NSInteger time;
@property (nonatomic, assign) NSInteger length;
@property (nonatomic, assign) NSInteger traficLight;

@end

typedef void(^MLRouteInfoBlock)(NSArray<NSDictionary *> *);


@interface MLObjectCMethodManager : NSObject
//- (void)showNaviRoutesMapView:(MAMapView*)mapView;
//- (void)showMultiColorNaviRoutes:(MAMapView*)mapView naviType:(NSInteger)naviType  withBlock:(MLRouteInfoBlock)block;
//
//- (MAOverlayRenderer *)mapView:(MAMapView *)mapView forOverlay:(id<MAOverlay>)overlay;
//
//- (void)selecteOverlayWithRouteID:(NSInteger)routeID mapView:(MAMapView*)mapView;
//- (NSArray<RouteCollectionViewInfo*>*)showMultiColorNaviRoutes:(MAMapView*)mapView;
@end

NS_ASSUME_NONNULL_END
