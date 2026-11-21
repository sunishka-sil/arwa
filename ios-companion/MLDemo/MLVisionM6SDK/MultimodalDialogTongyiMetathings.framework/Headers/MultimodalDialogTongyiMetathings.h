#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class MDTMAesCcmCipher, MDTMAnalyzeTokenSignRsp, MDTMAnalyzeTokenSignRspCompanion, MDTMApiClient, MDTMAtomicfuSynchronizedObject, MDTMBufferOverflow, MDTMCacheControl, MDTMCacheStorageCompanion, MDTMCachedResponseData, MDTMChannelFactory, MDTMChannelFlow<T>, MDTMChannelProvider, MDTMClientPluginBuilder<PluginConfig>, MDTMClientSSESession, MDTMClientSSESessionWithDeserialization, MDTMCloseableCoroutineDispatcher, MDTMConnectTimeoutException, MDTMCoroutineDispatcher, MDTMCoroutineDispatcherKey, MDTMCoroutineExceptionHandlerKey, MDTMCoroutineName, MDTMCoroutineNameKey, MDTMCoroutineStart, MDTMDataConversion, MDTMDefaultClientWebSocketSession, MDTMDefaultRequest, MDTMDefaultRequestDefaultRequestBuilder, MDTMDefaultRequestPlugin, MDTMDeviceAuthClientCompanion, MDTMDeviceInfoUtils, MDTMDeviceRegisterInfo, MDTMDeviceRegisterInfoCompanion, MDTMDeviceRegisterParams, MDTMDeviceRegisterParamsCompanion, MDTMDeviceRegisterRsp, MDTMDeviceRegisterRspCompanion, MDTMDispatchers, MDTMEmptyContent, MDTMExternalStorageManager, MDTMFormBuilder, MDTMFormPart<T>, MDTMGenGetTokenParams, MDTMGenGetTokenParamsCompanion, MDTMGlobalScope, MDTMHashUtils, MDTMHttpCache, MDTMHttpCacheCompanion, MDTMHttpCacheConfig, MDTMHttpCacheEntry, MDTMHttpCacheStorage, MDTMHttpCacheStorageCompanion, MDTMHttpCallValidatorConfig, MDTMHttpClient, MDTMHttpClientCall, MDTMHttpClientCallCompanion, MDTMHttpClientConfig<T>, MDTMHttpClientEngineConfig, MDTMHttpCookies, MDTMHttpCookiesCompanion, MDTMHttpCookiesConfig, MDTMHttpEngineFactory, MDTMHttpPlainTextConfig, MDTMHttpReceivePipeline, MDTMHttpReceivePipelinePhases, MDTMHttpRequestBuilder, MDTMHttpRequestBuilderCompanion, MDTMHttpRequestData, MDTMHttpRequestPipeline, MDTMHttpRequestPipelinePhases, MDTMHttpRequestRetryConfig, MDTMHttpRequestTimeoutException, MDTMHttpResponse, MDTMHttpResponseContainer, MDTMHttpResponseData, MDTMHttpResponsePipeline, MDTMHttpResponsePipelinePhases, MDTMHttpResponseReceiveFail, MDTMHttpRetryDelayContext, MDTMHttpRetryEventData, MDTMHttpRetryModifyRequestContext, MDTMHttpRetryShouldRetryContext, MDTMHttpSend, MDTMHttpSendConfig, MDTMHttpSendPipeline, MDTMHttpSendPipelinePhases, MDTMHttpSendPlugin, MDTMHttpStatement, MDTMHttpTimeoutCapability, MDTMHttpTimeoutConfig, MDTMHttpTimeoutConfigCompanion, MDTMInitParams, MDTMInitParamsCompanion, MDTMInputProvider, MDTMInterruptedIOException, MDTMJobKey, MDTMJobSupport, MDTMJsonContentTypeMatcher, MDTMKotlinAbstractCoroutineContextElement, MDTMKotlinAbstractCoroutineContextKey<B, E>, MDTMKotlinArray<T>, MDTMKotlinByteArray, MDTMKotlinByteIterator, MDTMKotlinCancellationException, MDTMKotlinEnum<E>, MDTMKotlinEnumCompanion, MDTMKotlinException, MDTMKotlinIllegalArgumentException, MDTMKotlinIllegalStateException, MDTMKotlinIntArray, MDTMKotlinIntIterator, MDTMKotlinIntProgression, MDTMKotlinIntProgressionCompanion, MDTMKotlinIntRange, MDTMKotlinIntRangeCompanion, MDTMKotlinKTypeProjection, MDTMKotlinKTypeProjectionCompanion, MDTMKotlinKVariance, MDTMKotlinLongArray, MDTMKotlinLongIterator, MDTMKotlinLongProgression, MDTMKotlinLongProgressionCompanion, MDTMKotlinLongRange, MDTMKotlinLongRangeCompanion, MDTMKotlinNoSuchElementException, MDTMKotlinNothing, MDTMKotlinRuntimeException, MDTMKotlinThrowable, MDTMKotlinUnit, MDTMKotlinUnsupportedOperationException, MDTMKotlinx_io_coreBuffer, MDTMKotlinx_io_coreIOException, MDTMKotlinx_serialization_coreSerialKind, MDTMKotlinx_serialization_coreSerializersModule, MDTMKotlinx_serialization_jsonJsonElement, MDTMKotlinx_serialization_jsonJsonElementCompanion, MDTMKtor_eventsEventDefinition<T>, MDTMKtor_eventsEvents, MDTMKtor_httpContentDisposition, MDTMKtor_httpContentDispositionCompanion, MDTMKtor_httpContentType, MDTMKtor_httpContentTypeCompanion, MDTMKtor_httpCookie, MDTMKtor_httpCookieCompanion, MDTMKtor_httpCookieEncoding, MDTMKtor_httpHeaderValueParam, MDTMKtor_httpHeaderValueWithParameters, MDTMKtor_httpHeaderValueWithParametersCompanion, MDTMKtor_httpHeadersBuilder, MDTMKtor_httpHttpMethod, MDTMKtor_httpHttpMethodCompanion, MDTMKtor_httpHttpProtocolVersion, MDTMKtor_httpHttpProtocolVersionCompanion, MDTMKtor_httpHttpStatusCode, MDTMKtor_httpHttpStatusCodeCompanion, MDTMKtor_httpOutgoingContent, MDTMKtor_httpOutgoingContentByteArrayContent, MDTMKtor_httpOutgoingContentContentWrapper, MDTMKtor_httpOutgoingContentNoContent, MDTMKtor_httpOutgoingContentWriteChannelContent, MDTMKtor_httpPartData, MDTMKtor_httpURLBuilder, MDTMKtor_httpURLBuilderCompanion, MDTMKtor_httpURLProtocol, MDTMKtor_httpURLProtocolCompanion, MDTMKtor_httpUrl, MDTMKtor_httpUrlCompanion, MDTMKtor_ioCharset, MDTMKtor_ioCharsetCompanion, MDTMKtor_ioCharsetDecoder, MDTMKtor_ioCharsetEncoder, MDTMKtor_sseTypedServerSentEvent<T>, MDTMKtor_utilsAttributeKey<T>, MDTMKtor_utilsDataConversion, MDTMKtor_utilsDataConversionConfiguration, MDTMKtor_utilsDelegatingConversionServiceConfiguration<T>, MDTMKtor_utilsGMTDate, MDTMKtor_utilsGMTDateCompanion, MDTMKtor_utilsMonth, MDTMKtor_utilsMonthCompanion, MDTMKtor_utilsNetworkAddress, MDTMKtor_utilsPipeline<TSubject, TContext>, MDTMKtor_utilsPipelinePhase, MDTMKtor_utilsStringValuesBuilderImpl, MDTMKtor_utilsTypeInfo, MDTMKtor_utilsWeekDay, MDTMKtor_utilsWeekDayCompanion, MDTMKtor_websocketsFrame, MDTMKtor_websocketsFrameCompanion, MDTMKtor_websocketsFrameType, MDTMKtor_websocketsFrameTypeCompanion, MDTMKtor_websocketsWebSocketExtensionHeader, MDTMKtor_websocketsWebSocketExtensionsConfig, MDTMLicenseSignatureParams, MDTMLicenseSignatureParamsCompanion, MDTMLockFreeLinkedListNode, MDTMLogger, MDTMMainCoroutineDispatcher, MDTMNonCancellable, MDTMNonDisposableHandle, MDTMPayMode, MDTMProxyBuilder, MDTMProxyConfig, MDTMProxyType, MDTMRandomHexUtils, MDTMResponseException, MDTMResult<T>, MDTMResultCompanion, MDTMResultError, MDTMSSECapability, MDTMSSEClientContent, MDTMSSEConfig, MDTMSend, MDTMSendingRequest, MDTMSetupRequest, MDTMSetupRequestContext, MDTMSharingCommand, MDTMSharingStartedCompanion, MDTMSocketTimeoutException, MDTMThreadSafeHeap<T>, MDTMTimeoutCancellationException, MDTMUnixSocketCapability, MDTMWebSocketCapability, MDTMWebSocketExtensionsCapability, MDTMWebSockets, MDTMWebSocketsConfig, MDTMWebSocketsPlugin, MDTMengines;

@protocol MDTMBailianBillingSignatureService, MDTMBroadcastChannel, MDTMCacheStorage, MDTMCancellableContinuation, MDTMChannel, MDTMChannelIterator, MDTMChildHandle, MDTMChildJob, MDTMClientHook, MDTMClientPlugin, MDTMClientWebSocketSession, MDTMCompletableDeferred, MDTMCompletableJob, MDTMCookiesStorage, MDTMCopyableThrowable, MDTMCoroutineExceptionHandler, MDTMCoroutineScope, MDTMDeferred, MDTMDeviceRegisterCallBack, MDTMDisposableHandle, MDTMFlow, MDTMFlowCollector, MDTMFusibleFlow, MDTMGetTokenCallBack, MDTMHttpClientEngine, MDTMHttpClientEngineCapability, MDTMHttpClientEngineFactory, MDTMHttpClientPlugin, MDTMHttpRequest, MDTMInitCallBack, MDTMJob, MDTMKotlinAnnotation, MDTMKotlinAutoCloseable, MDTMKotlinClosedRange, MDTMKotlinComparable, MDTMKotlinContinuation, MDTMKotlinContinuationInterceptor, MDTMKotlinCoroutineContext, MDTMKotlinCoroutineContextElement, MDTMKotlinCoroutineContextKey, MDTMKotlinFunction, MDTMKotlinIterable, MDTMKotlinIterator, MDTMKotlinKAnnotatedElement, MDTMKotlinKClass, MDTMKotlinKClassifier, MDTMKotlinKDeclarationContainer, MDTMKotlinKType, MDTMKotlinMapEntry, MDTMKotlinOpenEndRange, MDTMKotlinSequence, MDTMKotlinSuspendFunction0, MDTMKotlinSuspendFunction1, MDTMKotlinSuspendFunction2, MDTMKotlinSuspendFunction3, MDTMKotlinSuspendFunction4, MDTMKotlinSuspendFunction5, MDTMKotlinSuspendFunction6, MDTMKotlinx_io_coreRawSink, MDTMKotlinx_io_coreRawSource, MDTMKotlinx_io_coreSink, MDTMKotlinx_io_coreSource, MDTMKotlinx_serialization_coreCompositeDecoder, MDTMKotlinx_serialization_coreCompositeEncoder, MDTMKotlinx_serialization_coreDecoder, MDTMKotlinx_serialization_coreDeserializationStrategy, MDTMKotlinx_serialization_coreEncoder, MDTMKotlinx_serialization_coreKSerializer, MDTMKotlinx_serialization_coreSerialDescriptor, MDTMKotlinx_serialization_coreSerializationStrategy, MDTMKotlinx_serialization_coreSerializersModuleCollector, MDTMKtor_httpContentTypeMatcher, MDTMKtor_httpHeaders, MDTMKtor_httpHttpMessage, MDTMKtor_httpHttpMessageBuilder, MDTMKtor_httpParameters, MDTMKtor_httpParametersBuilder, MDTMKtor_ioByteReadChannel, MDTMKtor_ioByteWriteChannel, MDTMKtor_ioCloseable, MDTMKtor_ioJvmSerializable, MDTMKtor_serializationConfiguration, MDTMKtor_serializationContentConverter, MDTMKtor_serializationWebsocketContentConverter, MDTMKtor_sseServerSentEventMetadata, MDTMKtor_utilsAttributes, MDTMKtor_utilsConversionService, MDTMKtor_utilsStringValues, MDTMKtor_utilsStringValuesBuilder, MDTMKtor_websocketsDefaultWebSocketSession, MDTMKtor_websocketsWebSocketExtension, MDTMKtor_websocketsWebSocketExtensionFactory, MDTMKtor_websocketsWebSocketSession, MDTMMainDispatcherFactory, MDTMMutableSharedFlow, MDTMMutableStateFlow, MDTMMutex, MDTMParentJob, MDTMPlatform, MDTMProducerScope, MDTMProgressListener, MDTMReceiveChannel, MDTMResponseAdapter, MDTMRunnable, MDTMSSESession, MDTMSSESessionWithDeserialization, MDTMSelectBuilder, MDTMSelectClause, MDTMSelectClause0, MDTMSelectClause1, MDTMSelectClause2, MDTMSelectInstance, MDTMSemaphore, MDTMSendChannel, MDTMSharedFlow, MDTMSharingStarted, MDTMStateFlow;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface MDTMBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface MDTMBase (MDTMBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface MDTMMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface MDTMMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorMDTMKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface MDTMNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface MDTMByte : MDTMNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface MDTMUByte : MDTMNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface MDTMShort : MDTMNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface MDTMUShort : MDTMNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface MDTMInt : MDTMNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface MDTMUInt : MDTMNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface MDTMLong : MDTMNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface MDTMULong : MDTMNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface MDTMFloat : MDTMNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface MDTMDouble : MDTMNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface MDTMBoolean : MDTMNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceAuthClient")))
@interface MDTMDeviceAuthClient : MDTMBase
@property (class, readonly, getter=companion) MDTMDeviceAuthClientCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceAuthClient.Companion")))
@interface MDTMDeviceAuthClientCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMDeviceAuthClientCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) id<MDTMBailianBillingSignatureService> instance __attribute__((swift_name("instance")));
@end

__attribute__((swift_name("Platform")))
@protocol MDTMPlatform
@required
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("IOSPlatform")))
@interface MDTMIOSPlatform : MDTMBase <MDTMPlatform>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AnalyzeTokenSignRsp")))
@interface MDTMAnalyzeTokenSignRsp : MDTMBase
- (instancetype)initWithReqNonce:(NSString * _Nullable)reqNonce rspNonce:(NSString * _Nullable)rspNonce responseTime:(NSString * _Nullable)responseTime appId:(NSString * _Nullable)appId deviceName:(NSString * _Nullable)deviceName signature:(NSString * _Nullable)signature __attribute__((swift_name("init(reqNonce:rspNonce:responseTime:appId:deviceName:signature:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMAnalyzeTokenSignRspCompanion *companion __attribute__((swift_name("companion")));
- (MDTMAnalyzeTokenSignRsp *)doCopyReqNonce:(NSString * _Nullable)reqNonce rspNonce:(NSString * _Nullable)rspNonce responseTime:(NSString * _Nullable)responseTime appId:(NSString * _Nullable)appId deviceName:(NSString * _Nullable)deviceName signature:(NSString * _Nullable)signature __attribute__((swift_name("doCopy(reqNonce:rspNonce:responseTime:appId:deviceName:signature:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString * _Nullable appId __attribute__((swift_name("appId")));
@property NSString * _Nullable deviceName __attribute__((swift_name("deviceName")));
@property NSString * _Nullable reqNonce __attribute__((swift_name("reqNonce")));
@property NSString * _Nullable responseTime __attribute__((swift_name("responseTime")));
@property NSString * _Nullable rspNonce __attribute__((swift_name("rspNonce")));
@property NSString * _Nullable signature __attribute__((swift_name("signature")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AnalyzeTokenSignRsp.Companion")))
@interface MDTMAnalyzeTokenSignRspCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMAnalyzeTokenSignRspCompanion *shared __attribute__((swift_name("shared")));
- (id<MDTMKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceRegisterInfo")))
@interface MDTMDeviceRegisterInfo : MDTMBase
- (instancetype)initWithReqNonce:(NSString * _Nullable)reqNonce appId:(NSString * _Nullable)appId deviceName:(NSString * _Nullable)deviceName payMode:(NSString * _Nullable)payMode requestTime:(NSString * _Nullable)requestTime __attribute__((swift_name("init(reqNonce:appId:deviceName:payMode:requestTime:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMDeviceRegisterInfoCompanion *companion __attribute__((swift_name("companion")));
- (MDTMDeviceRegisterInfo *)doCopyReqNonce:(NSString * _Nullable)reqNonce appId:(NSString * _Nullable)appId deviceName:(NSString * _Nullable)deviceName payMode:(NSString * _Nullable)payMode requestTime:(NSString * _Nullable)requestTime __attribute__((swift_name("doCopy(reqNonce:appId:deviceName:payMode:requestTime:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString * _Nullable appId __attribute__((swift_name("appId")));
@property NSString * _Nullable deviceName __attribute__((swift_name("deviceName")));
@property NSString * _Nullable payMode __attribute__((swift_name("payMode")));
@property NSString * _Nullable reqNonce __attribute__((swift_name("reqNonce")));
@property NSString * _Nullable requestTime __attribute__((swift_name("requestTime")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceRegisterInfo.Companion")))
@interface MDTMDeviceRegisterInfoCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMDeviceRegisterInfoCompanion *shared __attribute__((swift_name("shared")));
- (id<MDTMKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceRegisterParams")))
@interface MDTMDeviceRegisterParams : MDTMBase
- (instancetype)initWithNonce:(NSString * _Nullable)nonce appId:(NSString * _Nullable)appId deviceName:(NSString * _Nullable)deviceName payMode:(NSString * _Nullable)payMode requestTime:(NSString * _Nullable)requestTime signature:(NSString * _Nullable)signature __attribute__((swift_name("init(nonce:appId:deviceName:payMode:requestTime:signature:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMDeviceRegisterParamsCompanion *companion __attribute__((swift_name("companion")));
- (MDTMDeviceRegisterParams *)doCopyNonce:(NSString * _Nullable)nonce appId:(NSString * _Nullable)appId deviceName:(NSString * _Nullable)deviceName payMode:(NSString * _Nullable)payMode requestTime:(NSString * _Nullable)requestTime signature:(NSString * _Nullable)signature __attribute__((swift_name("doCopy(nonce:appId:deviceName:payMode:requestTime:signature:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString * _Nullable appId __attribute__((swift_name("appId")));
@property NSString * _Nullable deviceName __attribute__((swift_name("deviceName")));
@property NSString * _Nullable nonce __attribute__((swift_name("nonce")));
@property NSString * _Nullable payMode __attribute__((swift_name("payMode")));
@property NSString * _Nullable requestTime __attribute__((swift_name("requestTime")));
@property NSString * _Nullable signature __attribute__((swift_name("signature")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceRegisterParams.Companion")))
@interface MDTMDeviceRegisterParamsCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMDeviceRegisterParamsCompanion *shared __attribute__((swift_name("shared")));
- (id<MDTMKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceRegisterRsp")))
@interface MDTMDeviceRegisterRsp : MDTMBase
- (instancetype)initWithAppId:(NSString * _Nullable)appId reqNonce:(NSString * _Nullable)reqNonce rspNonce:(NSString * _Nullable)rspNonce responseTime:(NSString * _Nullable)responseTime deviceName:(NSString * _Nullable)deviceName signature:(NSString * _Nullable)signature __attribute__((swift_name("init(appId:reqNonce:rspNonce:responseTime:deviceName:signature:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMDeviceRegisterRspCompanion *companion __attribute__((swift_name("companion")));
- (MDTMDeviceRegisterRsp *)doCopyAppId:(NSString * _Nullable)appId reqNonce:(NSString * _Nullable)reqNonce rspNonce:(NSString * _Nullable)rspNonce responseTime:(NSString * _Nullable)responseTime deviceName:(NSString * _Nullable)deviceName signature:(NSString * _Nullable)signature __attribute__((swift_name("doCopy(appId:reqNonce:rspNonce:responseTime:deviceName:signature:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString * _Nullable appId __attribute__((swift_name("appId")));
@property NSString * _Nullable deviceName __attribute__((swift_name("deviceName")));
@property NSString * _Nullable reqNonce __attribute__((swift_name("reqNonce")));
@property NSString * _Nullable responseTime __attribute__((swift_name("responseTime")));
@property NSString * _Nullable rspNonce __attribute__((swift_name("rspNonce")));
@property NSString * _Nullable signature __attribute__((swift_name("signature")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceRegisterRsp.Companion")))
@interface MDTMDeviceRegisterRspCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMDeviceRegisterRspCompanion *shared __attribute__((swift_name("shared")));
- (id<MDTMKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenGetTokenParams")))
@interface MDTMGenGetTokenParams : MDTMBase
- (instancetype)initWithNonce:(NSString * _Nullable)nonce appId:(NSString * _Nullable)appId apiKey:(NSString * _Nullable)apiKey deviceName:(NSString * _Nullable)deviceName payMode:(NSString * _Nullable)payMode requestTime:(NSString * _Nullable)requestTime signature:(NSString * _Nullable)signature tokenType:(NSString * _Nullable)tokenType __attribute__((swift_name("init(nonce:appId:apiKey:deviceName:payMode:requestTime:signature:tokenType:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMGenGetTokenParamsCompanion *companion __attribute__((swift_name("companion")));
- (MDTMGenGetTokenParams *)doCopyNonce:(NSString * _Nullable)nonce appId:(NSString * _Nullable)appId apiKey:(NSString * _Nullable)apiKey deviceName:(NSString * _Nullable)deviceName payMode:(NSString * _Nullable)payMode requestTime:(NSString * _Nullable)requestTime signature:(NSString * _Nullable)signature tokenType:(NSString * _Nullable)tokenType __attribute__((swift_name("doCopy(nonce:appId:apiKey:deviceName:payMode:requestTime:signature:tokenType:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString * _Nullable apiKey __attribute__((swift_name("apiKey")));
@property NSString * _Nullable appId __attribute__((swift_name("appId")));
@property NSString * _Nullable deviceName __attribute__((swift_name("deviceName")));
@property NSString * _Nullable nonce __attribute__((swift_name("nonce")));
@property NSString * _Nullable payMode __attribute__((swift_name("payMode")));
@property NSString * _Nullable requestTime __attribute__((swift_name("requestTime")));
@property NSString * _Nullable signature __attribute__((swift_name("signature")));
@property NSString * _Nullable tokenType __attribute__((swift_name("tokenType")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GenGetTokenParams.Companion")))
@interface MDTMGenGetTokenParamsCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMGenGetTokenParamsCompanion *shared __attribute__((swift_name("shared")));
- (id<MDTMKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InitParams")))
@interface MDTMInitParams : MDTMBase
- (instancetype)initWithAppId:(NSString *)appId appSecret:(NSString *)appSecret deviceName:(NSString *)deviceName __attribute__((swift_name("init(appId:appSecret:deviceName:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMInitParamsCompanion *companion __attribute__((swift_name("companion")));
@property NSString * _Nullable appId __attribute__((swift_name("appId")));
@property NSString * _Nullable appSecret __attribute__((swift_name("appSecret")));
@property NSString * _Nullable deviceName __attribute__((swift_name("deviceName")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InitParams.Companion")))
@interface MDTMInitParamsCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMInitParamsCompanion *shared __attribute__((swift_name("shared")));
- (id<MDTMKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LicenseSignatureParams")))
@interface MDTMLicenseSignatureParams : MDTMBase
- (instancetype)initWithAppId:(NSString * _Nullable)appId deviceName:(NSString * _Nullable)deviceName taskId:(NSString * _Nullable)taskId __attribute__((swift_name("init(appId:deviceName:taskId:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMLicenseSignatureParamsCompanion *companion __attribute__((swift_name("companion")));
@property NSString * _Nullable appId __attribute__((swift_name("appId")));
@property NSString * _Nullable deviceName __attribute__((swift_name("deviceName")));
@property NSString * _Nullable taskId __attribute__((swift_name("taskId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LicenseSignatureParams.Companion")))
@interface MDTMLicenseSignatureParamsCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMLicenseSignatureParamsCompanion *shared __attribute__((swift_name("shared")));
- (id<MDTMKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Result")))
@interface MDTMResult<T> : MDTMBase
- (instancetype)initWithSuccess:(BOOL)success code:(int32_t)code message:(NSString *)message data:(T _Nullable)data __attribute__((swift_name("init(success:code:message:data:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMResultCompanion *companion __attribute__((swift_name("companion")));
- (MDTMResult<T> *)doCopySuccess:(BOOL)success code:(int32_t)code message:(NSString *)message data:(T _Nullable)data __attribute__((swift_name("doCopy(success:code:message:data:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t code __attribute__((swift_name("code")));
@property (readonly) T _Nullable data __attribute__((swift_name("data")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@property (readonly) BOOL success __attribute__((swift_name("success")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ResultCompanion")))
@interface MDTMResultCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMResultCompanion *shared __attribute__((swift_name("shared")));
- (MDTMResult<id> *)errorCode:(int32_t)code message:(NSString *)message __attribute__((swift_name("error(code:message:)")));
- (MDTMResult<id> *)errorCode:(int32_t)code message:(NSString *)message data:(id _Nullable)data __attribute__((swift_name("error(code:message:data:)")));
- (MDTMResult<id> *)successData:(id _Nullable)data __attribute__((swift_name("success(data:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ResultError")))
@interface MDTMResultError : MDTMBase
- (instancetype)initWithCode:(MDTMInt * _Nullable)code message:(NSString * _Nullable)message __attribute__((swift_name("init(code:message:)"))) __attribute__((objc_designated_initializer));
- (MDTMResultError *)doCopyCode:(MDTMInt * _Nullable)code message:(NSString * _Nullable)message __attribute__((swift_name("doCopy(code:message:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property MDTMInt * _Nullable code __attribute__((swift_name("code")));
@property NSString * _Nullable message __attribute__((swift_name("message")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol MDTMKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface MDTMKotlinEnum<E> : MDTMBase <MDTMKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PayMode")))
@interface MDTMPayMode : MDTMKotlinEnum<MDTMPayMode *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) MDTMPayMode *payg __attribute__((swift_name("payg")));
@property (class, readonly) MDTMPayMode *license __attribute__((swift_name("license")));
+ (MDTMKotlinArray<MDTMPayMode *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<MDTMPayMode *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) NSString *payMode __attribute__((swift_name("payMode")));
@end

__attribute__((swift_name("BailianBillingSignatureService")))
@protocol MDTMBailianBillingSignatureService
@required
- (BOOL)deviceIsRegistered __attribute__((swift_name("deviceIsRegistered()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deviceRegisterParams:(MDTMDeviceRegisterParams *)params callBack:(id<MDTMDeviceRegisterCallBack>)callBack completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("deviceRegister(params:callBack:completionHandler:)")));
- (BOOL)deviceReset __attribute__((swift_name("deviceReset()")));
- (MDTMResult<NSString *> *)genGetTokenReqGetTokenParams:(MDTMGenGetTokenParams *)getTokenParams __attribute__((swift_name("genGetTokenReq(getTokenParams:)")));
- (MDTMResult<NSString *> *)genRegisterReqRegisterInfo:(MDTMDeviceRegisterInfo *)registerInfo __attribute__((swift_name("genRegisterReq(registerInfo:)")));
- (NSString *)getLicenseSignatureParams:(MDTMLicenseSignatureParams *)params __attribute__((swift_name("getLicenseSignature(params:)")));
- (MDTMResult<NSString *> *)getTokenTokenRsp:(MDTMAnalyzeTokenSignRsp *)tokenRsp __attribute__((swift_name("getToken(tokenRsp:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getTokenParams:(MDTMGenGetTokenParams *)params callBack:(id<MDTMGetTokenCallBack>)callBack completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("getToken(params:callBack:completionHandler:)")));
- (void)initializeParams:(MDTMInitParams *)params callBack:(id<MDTMInitCallBack>)callBack __attribute__((swift_name("initialize(params:callBack:)")));
- (MDTMResult<NSString *> *)writeDeviceInfoDeviceInfo:(MDTMDeviceRegisterRsp *)deviceInfo __attribute__((swift_name("writeDeviceInfo(deviceInfo:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BailianBillingSignatureServiceImpl")))
@interface MDTMBailianBillingSignatureServiceImpl : MDTMBase <MDTMBailianBillingSignatureService>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (BOOL)deviceIsRegistered __attribute__((swift_name("deviceIsRegistered()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deviceRegisterParams:(MDTMDeviceRegisterParams *)params callBack:(id<MDTMDeviceRegisterCallBack>)callBack completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("deviceRegister(params:callBack:completionHandler:)")));
- (BOOL)deviceReset __attribute__((swift_name("deviceReset()")));
- (MDTMResult<NSString *> *)genGetTokenReqGetTokenParams:(MDTMGenGetTokenParams *)getTokenParams __attribute__((swift_name("genGetTokenReq(getTokenParams:)")));
- (MDTMResult<NSString *> *)genRegisterReqRegisterInfo:(MDTMDeviceRegisterInfo *)registerInfo __attribute__((swift_name("genRegisterReq(registerInfo:)")));
- (NSString *)getLicenseSignatureParams:(MDTMLicenseSignatureParams *)params __attribute__((swift_name("getLicenseSignature(params:)")));
- (NSString * _Nullable)getString:(NSDictionary<NSString *, MDTMKotlinx_serialization_jsonJsonElement *> *)receiver key:(NSString *)key __attribute__((swift_name("getString(_:key:)")));
- (MDTMResult<NSString *> *)getTokenTokenRsp:(MDTMAnalyzeTokenSignRsp *)tokenRsp __attribute__((swift_name("getToken(tokenRsp:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getTokenParams:(MDTMGenGetTokenParams *)params callBack:(id<MDTMGetTokenCallBack>)callBack completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("getToken(params:callBack:completionHandler:)")));
- (void)initializeParams:(MDTMInitParams *)params callBack:(id<MDTMInitCallBack>)callBack __attribute__((swift_name("initialize(params:callBack:)")));
- (MDTMResult<NSString *> *)writeDeviceInfoDeviceInfo:(MDTMDeviceRegisterRsp *)deviceInfo __attribute__((swift_name("writeDeviceInfo(deviceInfo:)")));
@end

__attribute__((swift_name("DeviceRegisterCallBack")))
@protocol MDTMDeviceRegisterCallBack
@required
- (void)failError:(MDTMResultError *)error __attribute__((swift_name("fail(error:)")));
- (void)success __attribute__((swift_name("success()")));
@end

__attribute__((swift_name("GetTokenCallBack")))
@protocol MDTMGetTokenCallBack
@required
- (void)failError_:(MDTMResultError * _Nullable)error __attribute__((swift_name("fail(error_:)")));
- (void)successTokenInfo:(NSString * _Nullable)tokenInfo __attribute__((swift_name("success(tokenInfo:)")));
@end

__attribute__((swift_name("InitCallBack")))
@protocol MDTMInitCallBack
@required
- (void)failError:(MDTMResultError *)error __attribute__((swift_name("fail(error:)")));
- (void)success __attribute__((swift_name("success()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AesCcmCipher")))
@interface MDTMAesCcmCipher : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)aesCcmCipher __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMAesCcmCipher *shared __attribute__((swift_name("shared")));
- (NSString *)decryptEncryptedData:(NSString *)encryptedData key:(NSString *)key iv:(NSString *)iv __attribute__((swift_name("decrypt(encryptedData:key:iv:)")));
- (NSString *)encryptCiphertext:(MDTMKotlinByteArray *)ciphertext key:(MDTMKotlinByteArray *)key iv:(MDTMKotlinByteArray *)iv additionalData:(NSString * _Nullable)additionalData __attribute__((swift_name("encrypt(ciphertext:key:iv:additionalData:)")));
- (NSString *)generateKey __attribute__((swift_name("generateKey()")));
- (NSString *)hexByteArrayToStringHexBytes:(MDTMKotlinByteArray *)hexBytes __attribute__((swift_name("hexByteArrayToString(hexBytes:)")));
- (MDTMKotlinByteArray *)hexStringToByteArrayStr:(NSString *)str __attribute__((swift_name("hexStringToByteArray(str:)")));
- (NSString * _Nullable)hmacSHA256Str:(NSString *)str key:(NSString * _Nullable)key __attribute__((swift_name("hmacSHA256(str:key:)")));
- (MDTMKotlinByteArray *)xorByteArraysReqNonce:(MDTMKotlinByteArray *)reqNonce rspNonce:(MDTMKotlinByteArray *)rspNonce __attribute__((swift_name("xorByteArrays(reqNonce:rspNonce:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ApiClient")))
@interface MDTMApiClient : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)apiClient __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMApiClient *shared __attribute__((swift_name("shared")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deviceRegisterDeviceRegisterJsonStr:(NSString *)deviceRegisterJsonStr completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("deviceRegister(deviceRegisterJsonStr:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getTokenGetTokenJsonStr:(NSString *)getTokenJsonStr completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("getToken(getTokenJsonStr:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)postRequestUrl:(NSString *)url requestBody:(id)requestBody completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("postRequest(url:requestBody:completionHandler:)")));
@property (readonly) MDTMHttpClient *client __attribute__((swift_name("client")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceInfoUtils")))
@interface MDTMDeviceInfoUtils : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)deviceInfoUtils __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMDeviceInfoUtils *shared __attribute__((swift_name("shared")));
- (NSString * _Nullable)getDeviceId __attribute__((swift_name("getDeviceId()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ExternalStorageManager")))
@interface MDTMExternalStorageManager : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)externalStorageManager __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMExternalStorageManager *shared __attribute__((swift_name("shared")));
- (BOOL)deleteFileFileName:(NSString *)fileName __attribute__((swift_name("deleteFile(fileName:)")));
- (NSString * _Nullable)readJsonFromFileFileName:(NSString *)fileName __attribute__((swift_name("readJsonFromFile(fileName:)")));
- (BOOL)writeJsonToFileJsonString:(NSString *)jsonString fileName:(NSString *)fileName __attribute__((swift_name("writeJsonToFile(jsonString:fileName:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HashUtils")))
@interface MDTMHashUtils : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)hashUtils __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMHashUtils *shared __attribute__((swift_name("shared")));
- (NSString *)getSHA1Input:(NSString *)input __attribute__((swift_name("getSHA1(input:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpEngineFactory")))
@interface MDTMHttpEngineFactory : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)httpEngineFactory __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMHttpEngineFactory *shared __attribute__((swift_name("shared")));
- (id<MDTMHttpClientEngine>)createEngine __attribute__((swift_name("createEngine()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Logger")))
@interface MDTMLogger : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)logger __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMLogger *shared __attribute__((swift_name("shared")));
- (void)dTag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("d(tag:message:)")));
- (void)eTag:(NSString *)tag message:(NSString *)message throwable:(MDTMKotlinThrowable * _Nullable)throwable __attribute__((swift_name("e(tag:message:throwable:)")));
- (void)iTag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("i(tag:message:)")));
- (void)vTag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("v(tag:message:)")));
- (void)wTag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("w(tag:message:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RandomHexUtils")))
@interface MDTMRandomHexUtils : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)randomHexUtils __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMRandomHexUtils *shared __attribute__((swift_name("shared")));
- (NSString *)generateNormalHexLength:(int32_t)length __attribute__((swift_name("generateNormalHex(length:)")));
@end

__attribute__((swift_name("CoroutineScope")))
@protocol MDTMCoroutineScope
@required
@property (readonly) id<MDTMKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.0")
*/
__attribute__((swift_name("KotlinAutoCloseable")))
@protocol MDTMKotlinAutoCloseable
@required
- (void)close __attribute__((swift_name("close()")));
@end

__attribute__((swift_name("Ktor_ioCloseable")))
@protocol MDTMKtor_ioCloseable <MDTMKotlinAutoCloseable>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpClient")))
@interface MDTMHttpClient : MDTMBase <MDTMCoroutineScope, MDTMKtor_ioCloseable>
- (instancetype)initWithEngine:(id<MDTMHttpClientEngine>)engine userConfig:(MDTMHttpClientConfig<MDTMHttpClientEngineConfig *> *)userConfig __attribute__((swift_name("init(engine:userConfig:)"))) __attribute__((objc_designated_initializer));
- (void)close __attribute__((swift_name("close()")));
- (MDTMHttpClient *)configBlock:(void (^)(MDTMHttpClientConfig<id> *))block __attribute__((swift_name("config(block:)")));
- (BOOL)isSupportedCapability:(id<MDTMHttpClientEngineCapability>)capability __attribute__((swift_name("isSupported(capability:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<MDTMKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) id<MDTMKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property (readonly) id<MDTMHttpClientEngine> engine __attribute__((swift_name("engine")));
@property (readonly) MDTMHttpClientEngineConfig *engineConfig __attribute__((swift_name("engineConfig")));
@property (readonly) MDTMKtor_eventsEvents *monitor __attribute__((swift_name("monitor")));
@property (readonly) MDTMHttpReceivePipeline *receivePipeline __attribute__((swift_name("receivePipeline")));
@property (readonly) MDTMHttpRequestPipeline *requestPipeline __attribute__((swift_name("requestPipeline")));
@property (readonly) MDTMHttpResponsePipeline *responsePipeline __attribute__((swift_name("responsePipeline")));
@property (readonly) MDTMHttpSendPipeline *sendPipeline __attribute__((swift_name("sendPipeline")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpClientConfig")))
@interface MDTMHttpClientConfig<T> : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (MDTMHttpClientConfig<T> *)clone __attribute__((swift_name("clone()")));
- (void)engineBlock:(void (^)(T))block __attribute__((swift_name("engine(block:)")));
- (void)installClient:(MDTMHttpClient *)client __attribute__((swift_name("install(client:)")));
- (void)installPlugin:(id<MDTMHttpClientPlugin>)plugin configure:(void (^)(id))configure __attribute__((swift_name("install(plugin:configure:)")));
- (void)installKey:(NSString *)key block:(void (^)(MDTMHttpClient *))block __attribute__((swift_name("install(key:block:)")));
- (void)plusAssignOther:(MDTMHttpClientConfig<T> *)other __attribute__((swift_name("plusAssign(other:)")));
@property BOOL developmentMode __attribute__((swift_name("developmentMode"))) __attribute__((deprecated("Development mode is no longer required. The property will be removed in the future.")));
@property BOOL expectSuccess __attribute__((swift_name("expectSuccess")));
@property BOOL followRedirects __attribute__((swift_name("followRedirects")));
@property BOOL useDefaultTransformers __attribute__((swift_name("useDefaultTransformers")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface MDTMKotlinThrowable : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (MDTMKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) MDTMKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface MDTMKotlinException : MDTMKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface MDTMKotlinRuntimeException : MDTMKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface MDTMKotlinIllegalStateException : MDTMKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DoubleReceiveException")))
@interface MDTMDoubleReceiveException : MDTMKotlinIllegalStateException
- (instancetype)initWithCall:(MDTMHttpClientCall *)call __attribute__((swift_name("init(call:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end

__attribute__((swift_name("HttpClientCall")))
@interface MDTMHttpClientCall : MDTMBase <MDTMCoroutineScope>
- (instancetype)initWithClient:(MDTMHttpClient *)client __attribute__((swift_name("init(client:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithClient:(MDTMHttpClient *)client requestData:(MDTMHttpRequestData *)requestData responseData:(MDTMHttpResponseData *)responseData __attribute__((swift_name("init(client:requestData:responseData:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMHttpClientCallCompanion *companion __attribute__((swift_name("companion")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyInfo:(MDTMKtor_utilsTypeInfo *)info completionHandler:(void (^)(id _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("body(info:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyNullableInfo:(MDTMKtor_utilsTypeInfo *)info completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("bodyNullable(info:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)getResponseContentWithCompletionHandler:(void (^)(id<MDTMKtor_ioByteReadChannel> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getResponseContent(completionHandler:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) BOOL allowDoubleReceive __attribute__((swift_name("allowDoubleReceive")));
@property (readonly) id<MDTMKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) MDTMHttpClient *client __attribute__((swift_name("client")));
@property (readonly) id<MDTMKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property id<MDTMHttpRequest> request __attribute__((swift_name("request")));
@property MDTMHttpResponse *response __attribute__((swift_name("response")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpClientCall.Companion")))
@interface MDTMHttpClientCallCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMHttpClientCallCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("KotlinUnsupportedOperationException")))
@interface MDTMKotlinUnsupportedOperationException : MDTMKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NoTransformationFoundException")))
@interface MDTMNoTransformationFoundException : MDTMKotlinUnsupportedOperationException
- (instancetype)initWithResponse:(MDTMHttpResponse *)response from:(id<MDTMKotlinKClass>)from to:(id<MDTMKotlinKClass>)to __attribute__((swift_name("init(response:from:to:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ReceivePipelineException")))
@interface MDTMReceivePipelineException : MDTMKotlinIllegalStateException
- (instancetype)initWithRequest:(MDTMHttpClientCall *)request info:(MDTMKtor_utilsTypeInfo *)info cause:(MDTMKotlinThrowable *)cause __attribute__((swift_name("init(request:info:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) MDTMKotlinThrowable *cause __attribute__((swift_name("cause")));
@property (readonly) MDTMKtor_utilsTypeInfo *info __attribute__((swift_name("info")));
@property (readonly) MDTMHttpClientCall *request __attribute__((swift_name("request")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UnsupportedContentTypeException")))
@interface MDTMUnsupportedContentTypeException : MDTMKotlinIllegalStateException
- (instancetype)initWithContent:(MDTMKtor_httpOutgoingContent *)content __attribute__((swift_name("init(content:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinIllegalArgumentException")))
@interface MDTMKotlinIllegalArgumentException : MDTMKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UnsupportedUpgradeProtocolException")))
@interface MDTMUnsupportedUpgradeProtocolException : MDTMKotlinIllegalArgumentException
- (instancetype)initWithUrl:(MDTMKtor_httpUrl *)url __attribute__((swift_name("init(url:)"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("This exception is deprecated, use UnsupportedContentTypeException instead.")));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((swift_name("ProgressListener")))
@protocol MDTMProgressListener
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)onProgressBytesSentTotal:(int64_t)bytesSentTotal contentLength:(MDTMLong * _Nullable)contentLength completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("onProgress(bytesSentTotal:contentLength:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ClientEngineClosedException")))
@interface MDTMClientEngineClosedException : MDTMKotlinIllegalStateException
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) MDTMKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@end

__attribute__((swift_name("HttpClientEngine")))
@protocol MDTMHttpClientEngine <MDTMCoroutineScope, MDTMKtor_ioCloseable>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)executeData:(MDTMHttpRequestData *)data completionHandler:(void (^)(MDTMHttpResponseData * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("execute(data:completionHandler:)")));
- (void)installClient:(MDTMHttpClient *)client __attribute__((swift_name("install(client:)")));
@property (readonly) MDTMHttpClientEngineConfig *config __attribute__((swift_name("config")));
@property (readonly) MDTMCoroutineDispatcher *dispatcher __attribute__((swift_name("dispatcher")));
@property (readonly) NSSet<id<MDTMHttpClientEngineCapability>> *supportedCapabilities __attribute__((swift_name("supportedCapabilities")));
@end

__attribute__((swift_name("HttpClientEngineBase")))
@interface MDTMHttpClientEngineBase : MDTMBase <MDTMHttpClientEngine>
- (instancetype)initWithEngineName:(NSString *)engineName __attribute__((swift_name("init(engineName:)"))) __attribute__((objc_designated_initializer));
- (void)close __attribute__((swift_name("close()")));
@property (readonly) id<MDTMKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property (readonly) MDTMCoroutineDispatcher *dispatcher __attribute__((swift_name("dispatcher")));
@end

__attribute__((swift_name("HttpClientEngineCapability")))
@protocol MDTMHttpClientEngineCapability
@required
@end

__attribute__((swift_name("HttpClientEngineConfig")))
@interface MDTMHttpClientEngineConfig : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property MDTMCoroutineDispatcher * _Nullable dispatcher __attribute__((swift_name("dispatcher")));
@property BOOL pipelining __attribute__((swift_name("pipelining")));
@property MDTMProxyConfig * _Nullable proxy __attribute__((swift_name("proxy")));
@property int32_t threadsCount __attribute__((swift_name("threadsCount"))) __attribute__((unavailable("The [threadsCount] property is deprecated. Consider setting [dispatcher] instead.")));
@end

__attribute__((swift_name("HttpClientEngineFactory")))
@protocol MDTMHttpClientEngineFactory
@required
- (id<MDTMHttpClientEngine>)createBlock:(void (^)(MDTMHttpClientEngineConfig *))block __attribute__((swift_name("create(block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProxyBuilder")))
@interface MDTMProxyBuilder : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)proxyBuilder __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMProxyBuilder *shared __attribute__((swift_name("shared")));
- (MDTMProxyConfig *)httpUrl:(MDTMKtor_httpUrl *)url __attribute__((swift_name("http(url:)")));
- (MDTMProxyConfig *)socksHost:(NSString *)host port:(int32_t)port __attribute__((swift_name("socks(host:port:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProxyConfig")))
@interface MDTMProxyConfig : MDTMBase
- (instancetype)initWithUrl:(MDTMKtor_httpUrl *)url __attribute__((swift_name("init(url:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) MDTMKtor_httpUrl *url __attribute__((swift_name("url")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProxyType")))
@interface MDTMProxyType : MDTMKotlinEnum<MDTMProxyType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) MDTMProxyType *socks __attribute__((swift_name("socks")));
@property (class, readonly) MDTMProxyType *http __attribute__((swift_name("http")));
@property (class, readonly) MDTMProxyType *unknown __attribute__((swift_name("unknown")));
+ (MDTMKotlinArray<MDTMProxyType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<MDTMProxyType *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((swift_name("KotlinIterable")))
@protocol MDTMKotlinIterable
@required
- (id<MDTMKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("engines")))
@interface MDTMengines : MDTMBase <MDTMKotlinIterable>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)engines __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMengines *shared __attribute__((swift_name("shared")));
- (void)appendItem:(id<MDTMHttpClientEngineFactory>)item __attribute__((swift_name("append(item:)")));
- (id<MDTMKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end

__attribute__((swift_name("Kotlinx_io_coreIOException")))
@interface MDTMKotlinx_io_coreIOException : MDTMKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConnectTimeoutException")))
@interface MDTMConnectTimeoutException : MDTMKotlinx_io_coreIOException
- (instancetype)initWithMessage:(NSString *)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((swift_name("InterruptedIOException")))
@interface MDTMInterruptedIOException : MDTMKotlinx_io_coreIOException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SocketTimeoutException")))
@interface MDTMSocketTimeoutException : MDTMInterruptedIOException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
@property (readonly) MDTMKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
@end

__attribute__((swift_name("ResponseException")))
@interface MDTMResponseException : MDTMKotlinIllegalStateException
- (instancetype)initWithResponse:(MDTMHttpResponse *)response cachedResponseText:(NSString *)cachedResponseText __attribute__((swift_name("init(response:cachedResponseText:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) MDTMHttpResponse *response __attribute__((swift_name("response")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ClientRequestException")))
@interface MDTMClientRequestException : MDTMResponseException
- (instancetype)initWithResponse:(MDTMHttpResponse *)response cachedResponseText:(NSString *)cachedResponseText __attribute__((swift_name("init(response:cachedResponseText:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end

__attribute__((swift_name("HttpClientPlugin")))
@protocol MDTMHttpClientPlugin
@required
- (void)installPlugin:(id)plugin scope:(MDTMHttpClient *)scope __attribute__((swift_name("install(plugin:scope:)")));
- (id)prepareBlock:(void (^)(id))block __attribute__((swift_name("prepare(block:)")));
@property (readonly) MDTMKtor_utilsAttributeKey<id> *key __attribute__((swift_name("key")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DataConversion")))
@interface MDTMDataConversion : MDTMBase <MDTMHttpClientPlugin>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dataConversion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMDataConversion *shared __attribute__((swift_name("shared")));
- (void)installPlugin:(MDTMKtor_utilsDataConversion *)plugin scope:(MDTMHttpClient *)scope __attribute__((swift_name("install(plugin:scope:)")));
- (MDTMKtor_utilsDataConversion *)prepareBlock:(void (^)(MDTMKtor_utilsDataConversionConfiguration *))block __attribute__((swift_name("prepare(block:)")));
@property (readonly) MDTMKtor_utilsAttributeKey<MDTMKtor_utilsDataConversion *> *key __attribute__((swift_name("key")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DefaultRequest")))
@interface MDTMDefaultRequest : MDTMBase
@property (class, readonly, getter=companion) MDTMDefaultRequestPlugin *companion __attribute__((swift_name("companion")));
@end

__attribute__((swift_name("Ktor_httpHttpMessageBuilder")))
@protocol MDTMKtor_httpHttpMessageBuilder
@required
@property (readonly) MDTMKtor_httpHeadersBuilder *headers __attribute__((swift_name("headers")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DefaultRequest.DefaultRequestBuilder")))
@interface MDTMDefaultRequestDefaultRequestBuilder : MDTMBase <MDTMKtor_httpHttpMessageBuilder>
- (void)setAttributesBlock:(void (^)(id<MDTMKtor_utilsAttributes>))block __attribute__((swift_name("setAttributes(block:)")));
- (void)setCapabilityKey:(id<MDTMHttpClientEngineCapability>)key capability:(id)capability __attribute__((swift_name("setCapability(key:capability:)")));
- (void)unixSocketPath:(NSString *)path __attribute__((swift_name("unixSocket(path:)")));
- (void)urlBlock:(void (^)(MDTMKtor_httpURLBuilder *))block __attribute__((swift_name("url(block:)")));
- (void)urlUrlString:(NSString *)urlString __attribute__((swift_name("url(urlString:)")));
- (void)urlScheme:(NSString * _Nullable)scheme host:(NSString * _Nullable)host port:(MDTMInt * _Nullable)port path:(NSString * _Nullable)path block:(void (^)(MDTMKtor_httpURLBuilder *))block __attribute__((swift_name("url(scheme:host:port:path:block:)")));
@property (readonly) id<MDTMKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) MDTMKtor_httpHeadersBuilder *headers __attribute__((swift_name("headers")));
@property NSString *host __attribute__((swift_name("host")));
@property int32_t port __attribute__((swift_name("port")));
@property (readonly) MDTMKtor_httpURLBuilder *url __attribute__((swift_name("url")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DefaultRequest.Plugin")))
@interface MDTMDefaultRequestPlugin : MDTMBase <MDTMHttpClientPlugin>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)plugin __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMDefaultRequestPlugin *shared __attribute__((swift_name("shared")));
- (void)installPlugin:(MDTMDefaultRequest *)plugin scope:(MDTMHttpClient *)scope __attribute__((swift_name("install(plugin:scope:)")));
- (MDTMDefaultRequest *)prepareBlock:(void (^)(MDTMDefaultRequestDefaultRequestBuilder *))block __attribute__((swift_name("prepare(block:)")));
@property (readonly) MDTMKtor_utilsAttributeKey<MDTMDefaultRequest *> *key __attribute__((swift_name("key")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpCallValidatorConfig")))
@interface MDTMHttpCallValidatorConfig : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)handleResponseExceptionBlock:(id<MDTMKotlinSuspendFunction2>)block __attribute__((swift_name("handleResponseException(block:)")));
- (void)handleResponseExceptionWithRequestBlock:(id<MDTMKotlinSuspendFunction2>)block __attribute__((swift_name("handleResponseExceptionWithRequest(block:)")));
- (void)validateResponseBlock:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("validateResponse(block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpPlainTextConfig")))
@interface MDTMHttpPlainTextConfig : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)registerCharset:(MDTMKtor_ioCharset *)charset quality:(MDTMFloat * _Nullable)quality __attribute__((swift_name("register(charset:quality:)")));
@property MDTMKtor_ioCharset *responseCharsetFallback __attribute__((swift_name("responseCharsetFallback")));
@property MDTMKtor_ioCharset * _Nullable sendCharset __attribute__((swift_name("sendCharset")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRedirectConfig")))
@interface MDTMHttpRedirectConfig : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property BOOL allowHttpsDowngrade __attribute__((swift_name("allowHttpsDowngrade")));
@property BOOL checkHttpMethod __attribute__((swift_name("checkHttpMethod")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRequestRetryConfig")))
@interface MDTMHttpRequestRetryConfig : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)constantDelayMillis:(int64_t)millis randomizationMs:(int64_t)randomizationMs respectRetryAfterHeader:(BOOL)respectRetryAfterHeader __attribute__((swift_name("constantDelay(millis:randomizationMs:respectRetryAfterHeader:)")));
- (void)delayBlock:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("delay(block:)")));
- (void)delayMillisRespectRetryAfterHeader:(BOOL)respectRetryAfterHeader block:(MDTMLong *(^)(MDTMHttpRetryDelayContext *, MDTMInt *))block __attribute__((swift_name("delayMillis(respectRetryAfterHeader:block:)")));
- (void)exponentialDelayBase:(double)base baseDelayMs:(int64_t)baseDelayMs maxDelayMs:(int64_t)maxDelayMs randomizationMs:(int64_t)randomizationMs respectRetryAfterHeader:(BOOL)respectRetryAfterHeader __attribute__((swift_name("exponentialDelay(base:baseDelayMs:maxDelayMs:randomizationMs:respectRetryAfterHeader:)")));
- (void)modifyRequestBlock:(void (^)(MDTMHttpRetryModifyRequestContext *, MDTMHttpRequestBuilder *))block __attribute__((swift_name("modifyRequest(block:)")));
- (void)noRetry __attribute__((swift_name("noRetry()")));
- (void)retryIfMaxRetries:(int32_t)maxRetries block:(MDTMBoolean *(^)(MDTMHttpRetryShouldRetryContext *, id<MDTMHttpRequest>, MDTMHttpResponse *))block __attribute__((swift_name("retryIf(maxRetries:block:)")));
- (void)retryOnExceptionMaxRetries:(int32_t)maxRetries retryOnTimeout:(BOOL)retryOnTimeout __attribute__((swift_name("retryOnException(maxRetries:retryOnTimeout:)")));
- (void)retryOnExceptionIfMaxRetries:(int32_t)maxRetries block:(MDTMBoolean *(^)(MDTMHttpRetryShouldRetryContext *, MDTMHttpRequestBuilder *, MDTMKotlinThrowable *))block __attribute__((swift_name("retryOnExceptionIf(maxRetries:block:)")));
- (void)retryOnExceptionOrServerErrorsMaxRetries:(int32_t)maxRetries __attribute__((swift_name("retryOnExceptionOrServerErrors(maxRetries:)")));
- (void)retryOnServerErrorsMaxRetries:(int32_t)maxRetries __attribute__((swift_name("retryOnServerErrors(maxRetries:)")));
@property int32_t maxRetries __attribute__((swift_name("maxRetries")));
@property (readonly) void (^modifyRequest)(MDTMHttpRetryModifyRequestContext *, MDTMHttpRequestBuilder *) __attribute__((swift_name("modifyRequest")));
@property (readonly) MDTMBoolean *(^ _Nullable retryIf)(MDTMHttpRetryShouldRetryContext *, id<MDTMHttpRequest>, MDTMHttpResponse *) __attribute__((swift_name("retryIf")));
@property (readonly) MDTMBoolean *(^ _Nullable retryOnExceptionIf)(MDTMHttpRetryShouldRetryContext *, MDTMHttpRequestBuilder *, MDTMKotlinThrowable *) __attribute__((swift_name("retryOnExceptionIf")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
__attribute__((swift_name("CopyableThrowable")))
@protocol MDTMCopyableThrowable
@required
- (MDTMKotlinThrowable * _Nullable)createCopy __attribute__((swift_name("createCopy()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRequestTimeoutException")))
@interface MDTMHttpRequestTimeoutException : MDTMKotlinx_io_coreIOException <MDTMCopyableThrowable>
- (instancetype)initWithRequest:(MDTMHttpRequestBuilder *)request __attribute__((swift_name("init(request:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithRequest_:(MDTMHttpRequestData *)request __attribute__((swift_name("init(request_:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithUrl:(NSString *)url timeoutMillis:(MDTMLong * _Nullable)timeoutMillis cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(url:timeoutMillis:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (MDTMHttpRequestTimeoutException *)createCopy __attribute__((swift_name("createCopy()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRetryDelayContext")))
@interface MDTMHttpRetryDelayContext : MDTMBase
@property (readonly) MDTMKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) MDTMHttpRequestBuilder *request __attribute__((swift_name("request")));
@property (readonly) MDTMHttpResponse * _Nullable response __attribute__((swift_name("response")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRetryEventData")))
@interface MDTMHttpRetryEventData : MDTMBase
@property (readonly) MDTMKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) MDTMHttpRequestBuilder *request __attribute__((swift_name("request")));
@property (readonly) MDTMHttpResponse * _Nullable response __attribute__((swift_name("response")));
@property (readonly) int32_t retryCount __attribute__((swift_name("retryCount")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRetryModifyRequestContext")))
@interface MDTMHttpRetryModifyRequestContext : MDTMBase
@property (readonly) MDTMKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) MDTMHttpRequestBuilder *request __attribute__((swift_name("request")));
@property (readonly) MDTMHttpResponse * _Nullable response __attribute__((swift_name("response")));
@property (readonly) int32_t retryCount __attribute__((swift_name("retryCount")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRetryShouldRetryContext")))
@interface MDTMHttpRetryShouldRetryContext : MDTMBase
- (instancetype)initWithRetryCount:(int32_t)retryCount __attribute__((swift_name("init(retryCount:)"))) __attribute__((objc_designated_initializer));
@property (readonly) int32_t retryCount __attribute__((swift_name("retryCount")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpSend")))
@interface MDTMHttpSend : MDTMBase
@property (class, readonly, getter=companion) MDTMHttpSendPlugin *companion __attribute__((swift_name("companion")));
- (void)interceptBlock:(id<MDTMKotlinSuspendFunction2>)block __attribute__((swift_name("intercept(block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpSend.Config")))
@interface MDTMHttpSendConfig : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property int32_t maxSendCount __attribute__((swift_name("maxSendCount")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpSend.Plugin")))
@interface MDTMHttpSendPlugin : MDTMBase <MDTMHttpClientPlugin>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)plugin __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMHttpSendPlugin *shared __attribute__((swift_name("shared")));
- (void)installPlugin:(MDTMHttpSend *)plugin scope:(MDTMHttpClient *)scope __attribute__((swift_name("install(plugin:scope:)")));
- (MDTMHttpSend *)prepareBlock:(void (^)(MDTMHttpSendConfig *))block __attribute__((swift_name("prepare(block:)")));
@property (readonly) MDTMKtor_utilsAttributeKey<MDTMHttpSend *> *key __attribute__((swift_name("key")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpTimeoutCapability")))
@interface MDTMHttpTimeoutCapability : MDTMBase <MDTMHttpClientEngineCapability>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)httpTimeoutCapability __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMHttpTimeoutCapability *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpTimeoutConfig")))
@interface MDTMHttpTimeoutConfig : MDTMBase
- (instancetype)initWithRequestTimeoutMillis:(MDTMLong * _Nullable)requestTimeoutMillis connectTimeoutMillis:(MDTMLong * _Nullable)connectTimeoutMillis socketTimeoutMillis:(MDTMLong * _Nullable)socketTimeoutMillis __attribute__((swift_name("init(requestTimeoutMillis:connectTimeoutMillis:socketTimeoutMillis:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMHttpTimeoutConfigCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
@property MDTMLong * _Nullable connectTimeoutMillis __attribute__((swift_name("connectTimeoutMillis")));
@property MDTMLong * _Nullable requestTimeoutMillis __attribute__((swift_name("requestTimeoutMillis")));
@property MDTMLong * _Nullable socketTimeoutMillis __attribute__((swift_name("socketTimeoutMillis")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpTimeoutConfig.Companion")))
@interface MDTMHttpTimeoutConfigCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMHttpTimeoutConfigCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) int64_t INFINITE_TIMEOUT_MS __attribute__((swift_name("INFINITE_TIMEOUT_MS")));
@property (readonly) MDTMKtor_utilsAttributeKey<MDTMHttpTimeoutConfig *> *key __attribute__((swift_name("key")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RedirectResponseException")))
@interface MDTMRedirectResponseException : MDTMResponseException
- (instancetype)initWithResponse:(MDTMHttpResponse *)response cachedResponseText:(NSString *)cachedResponseText __attribute__((swift_name("init(response:cachedResponseText:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SaveBodyPluginConfig")))
@interface MDTMSaveBodyPluginConfig : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("This plugin is no longer needed.\nThis API is deprecated and will be removed in Ktor 4.0.0")));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property BOOL disabled __attribute__((swift_name("disabled"))) __attribute__((deprecated("It is no longer possible to disable body saving for all requests. Use client.prepareRequest(...).execute { ... } syntax to prevent saving the body in memory.\n\nThis API is deprecated and will be removed in Ktor 4.0.0\nIf you were relying on this functionality, share your use case by commenting on this issue: https://youtrack.jetbrains.com/issue/KTOR-8367/")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SendCountExceedException")))
@interface MDTMSendCountExceedException : MDTMKotlinIllegalStateException
- (instancetype)initWithMessage:(NSString *)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((swift_name("Sender")))
@protocol MDTMSender
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)executeRequestBuilder:(MDTMHttpRequestBuilder *)requestBuilder completionHandler:(void (^)(MDTMHttpClientCall * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("execute(requestBuilder:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ServerResponseException")))
@interface MDTMServerResponseException : MDTMResponseException
- (instancetype)initWithResponse:(MDTMHttpResponse *)response cachedResponseText:(NSString *)cachedResponseText __attribute__((swift_name("init(response:cachedResponseText:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end

__attribute__((swift_name("ClientHook")))
@protocol MDTMClientHook
@required
- (void)installClient:(MDTMHttpClient *)client handler:(id _Nullable)handler __attribute__((swift_name("install(client:handler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SetupRequestContext")))
@interface MDTMSetupRequestContext : MDTMBase <MDTMClientHook>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)setupRequestContext __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMSetupRequestContext *shared __attribute__((swift_name("shared")));
- (void)installClient:(MDTMHttpClient *)client handler:(id<MDTMKotlinSuspendFunction2>)handler __attribute__((swift_name("install(client:handler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UserAgentConfig")))
@interface MDTMUserAgentConfig : MDTMBase
- (instancetype)initWithAgent:(NSString *)agent __attribute__((swift_name("init(agent:)"))) __attribute__((objc_designated_initializer));
@property NSString *agent __attribute__((swift_name("agent")));
@end

__attribute__((swift_name("ClientPlugin")))
@protocol MDTMClientPlugin <MDTMHttpClientPlugin>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ClientPluginBuilder")))
@interface MDTMClientPluginBuilder<PluginConfig> : MDTMBase
- (void)onHook:(id<MDTMClientHook>)hook handler:(id _Nullable)handler __attribute__((swift_name("on(hook:handler:)")));
- (void)onCloseBlock:(void (^)(void))block __attribute__((swift_name("onClose(block:)")));
- (void)onRequestBlock:(id<MDTMKotlinSuspendFunction3>)block __attribute__((swift_name("onRequest(block:)")));
- (void)onResponseBlock:(id<MDTMKotlinSuspendFunction2>)block __attribute__((swift_name("onResponse(block:)")));
- (void)transformRequestBodyBlock:(id<MDTMKotlinSuspendFunction4>)block __attribute__((swift_name("transformRequestBody(block:)")));
- (void)transformResponseBodyBlock:(id<MDTMKotlinSuspendFunction4>)block __attribute__((swift_name("transformResponseBody(block:)")));
@property (readonly) MDTMHttpClient *client __attribute__((swift_name("client")));
@property (readonly) PluginConfig pluginConfig __attribute__((swift_name("pluginConfig")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ClientPluginInstance")))
@interface MDTMClientPluginInstance<PluginConfig> : MDTMBase <MDTMKtor_ioCloseable>
- (void)close __attribute__((swift_name("close()")));
- (void)installScope:(MDTMHttpClient *)scope __attribute__((swift_name("install(scope:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MonitoringEvent")))
@interface MDTMMonitoringEvent<Param, Event> : MDTMBase <MDTMClientHook>
- (instancetype)initWithEvent:(Event)event __attribute__((swift_name("init(event:)"))) __attribute__((objc_designated_initializer));
- (void)installClient:(MDTMHttpClient *)client handler:(MDTMKotlinUnit *(^)(Param))handler __attribute__((swift_name("install(client:handler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OnRequestContext")))
@interface MDTMOnRequestContext : MDTMBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OnResponseContext")))
@interface MDTMOnResponseContext : MDTMBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Send")))
@interface MDTMSend : MDTMBase <MDTMClientHook>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)send __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMSend *shared __attribute__((swift_name("shared")));
- (void)installClient:(MDTMHttpClient *)client handler:(id<MDTMKotlinSuspendFunction2>)handler __attribute__((swift_name("install(client:handler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Send.Sender")))
@interface MDTMSendSender : MDTMBase <MDTMCoroutineScope>

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)proceedRequestBuilder:(MDTMHttpRequestBuilder *)requestBuilder completionHandler:(void (^)(MDTMHttpClientCall * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("proceed(requestBuilder:completionHandler:)")));
@property (readonly) id<MDTMKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SendingRequest")))
@interface MDTMSendingRequest : MDTMBase <MDTMClientHook>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)sendingRequest __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMSendingRequest *shared __attribute__((swift_name("shared")));
- (void)installClient:(MDTMHttpClient *)client handler:(id<MDTMKotlinSuspendFunction2>)handler __attribute__((swift_name("install(client:handler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SetupRequest")))
@interface MDTMSetupRequest : MDTMBase <MDTMClientHook>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)setupRequest __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMSetupRequest *shared __attribute__((swift_name("shared")));
- (void)installClient:(MDTMHttpClient *)client handler:(id<MDTMKotlinSuspendFunction1>)handler __attribute__((swift_name("install(client:handler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TransformRequestBodyContext")))
@interface MDTMTransformRequestBodyContext : MDTMBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TransformResponseBodyContext")))
@interface MDTMTransformResponseBodyContext : MDTMBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpCache")))
@interface MDTMHttpCache : MDTMBase
@property (class, readonly, getter=companion) MDTMHttpCacheCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpCache.Companion")))
@interface MDTMHttpCacheCompanion : MDTMBase <MDTMHttpClientPlugin>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMHttpCacheCompanion *shared __attribute__((swift_name("shared")));
- (void)installPlugin:(MDTMHttpCache *)plugin scope:(MDTMHttpClient *)scope __attribute__((swift_name("install(plugin:scope:)")));
- (MDTMHttpCache *)prepareBlock:(void (^)(MDTMHttpCacheConfig *))block __attribute__((swift_name("prepare(block:)")));
@property (readonly) MDTMKtor_eventsEventDefinition<MDTMHttpResponse *> *HttpResponseFromCache __attribute__((swift_name("HttpResponseFromCache")));
@property (readonly) MDTMKtor_utilsAttributeKey<MDTMHttpCache *> *key __attribute__((swift_name("key")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpCache.Config")))
@interface MDTMHttpCacheConfig : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)privateStorageStorage:(id<MDTMCacheStorage>)storage __attribute__((swift_name("privateStorage(storage:)")));
- (void)publicStorageStorage:(id<MDTMCacheStorage>)storage __attribute__((swift_name("publicStorage(storage:)")));
@property BOOL isShared __attribute__((swift_name("isShared")));
@property MDTMHttpCacheStorage *privateStorage __attribute__((swift_name("privateStorage"))) __attribute__((unavailable("This will become internal. Use setter method instead with new storage interface")));
@property MDTMHttpCacheStorage *publicStorage __attribute__((swift_name("publicStorage"))) __attribute__((unavailable("This will become internal. Use setter method instead with new storage interface")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpCacheEntry")))
@interface MDTMHttpCacheEntry : MDTMBase
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
@property (readonly) MDTMKotlinByteArray *body __attribute__((swift_name("body")));
@property (readonly) MDTMKtor_utilsGMTDate *expires __attribute__((swift_name("expires")));
@property (readonly) MDTMHttpResponse *response __attribute__((swift_name("response")));
@property (readonly) NSDictionary<NSString *, NSString *> *varyKeys __attribute__((swift_name("varyKeys")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InvalidCacheStateException")))
@interface MDTMInvalidCacheStateException : MDTMKotlinIllegalStateException
- (instancetype)initWithRequestUrl:(MDTMKtor_httpUrl *)requestUrl __attribute__((swift_name("init(requestUrl:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((swift_name("CacheStorage")))
@protocol MDTMCacheStorage
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)findUrl:(MDTMKtor_httpUrl *)url varyKeys:(NSDictionary<NSString *, NSString *> *)varyKeys completionHandler:(void (^)(MDTMCachedResponseData * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("find(url:varyKeys:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)findAllUrl:(MDTMKtor_httpUrl *)url completionHandler:(void (^)(NSSet<MDTMCachedResponseData *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("findAll(url:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)removeUrl:(MDTMKtor_httpUrl *)url varyKeys:(NSDictionary<NSString *, NSString *> *)varyKeys completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("remove(url:varyKeys:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)removeAllUrl:(MDTMKtor_httpUrl *)url completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("removeAll(url:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)storeUrl:(MDTMKtor_httpUrl *)url data:(MDTMCachedResponseData *)data completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("store(url:data:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CacheStorageCompanion")))
@interface MDTMCacheStorageCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMCacheStorageCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) id<MDTMCacheStorage> Disabled __attribute__((swift_name("Disabled")));
@property (readonly) id<MDTMCacheStorage> (^Unlimited)(void) __attribute__((swift_name("Unlimited")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CachedResponseData")))
@interface MDTMCachedResponseData : MDTMBase
- (instancetype)initWithUrl:(MDTMKtor_httpUrl *)url statusCode:(MDTMKtor_httpHttpStatusCode *)statusCode requestTime:(MDTMKtor_utilsGMTDate *)requestTime responseTime:(MDTMKtor_utilsGMTDate *)responseTime version:(MDTMKtor_httpHttpProtocolVersion *)version expires:(MDTMKtor_utilsGMTDate *)expires headers:(id<MDTMKtor_httpHeaders>)headers varyKeys:(NSDictionary<NSString *, NSString *> *)varyKeys body:(MDTMKotlinByteArray *)body __attribute__((swift_name("init(url:statusCode:requestTime:responseTime:version:expires:headers:varyKeys:body:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
@property (readonly) MDTMKotlinByteArray *body __attribute__((swift_name("body")));
@property (readonly) MDTMKtor_utilsGMTDate *expires __attribute__((swift_name("expires")));
@property (readonly) id<MDTMKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) MDTMKtor_utilsGMTDate *requestTime __attribute__((swift_name("requestTime")));
@property (readonly) MDTMKtor_utilsGMTDate *responseTime __attribute__((swift_name("responseTime")));
@property (readonly) MDTMKtor_httpHttpStatusCode *statusCode __attribute__((swift_name("statusCode")));
@property (readonly) MDTMKtor_httpUrl *url __attribute__((swift_name("url")));
@property (readonly) NSDictionary<NSString *, NSString *> *varyKeys __attribute__((swift_name("varyKeys")));
@property (readonly) MDTMKtor_httpHttpProtocolVersion *version __attribute__((swift_name("version")));
@end

__attribute__((swift_name("HttpCacheStorage")))
@interface MDTMHttpCacheStorage : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable("Use new [CacheStorage] instead.")));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) MDTMHttpCacheStorageCompanion *companion __attribute__((swift_name("companion")));
- (MDTMHttpCacheEntry * _Nullable)findUrl:(MDTMKtor_httpUrl *)url varyKeys:(NSDictionary<NSString *, NSString *> *)varyKeys __attribute__((swift_name("find(url:varyKeys:)")));
- (NSSet<MDTMHttpCacheEntry *> *)findByUrlUrl:(MDTMKtor_httpUrl *)url __attribute__((swift_name("findByUrl(url:)")));
- (void)storeUrl:(MDTMKtor_httpUrl *)url value:(MDTMHttpCacheEntry *)value __attribute__((swift_name("store(url:value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpCacheStorage.Companion")))
@interface MDTMHttpCacheStorageCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMHttpCacheStorageCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) MDTMHttpCacheStorage *Disabled __attribute__((swift_name("Disabled")));
@property (readonly) MDTMHttpCacheStorage *(^Unlimited)(void) __attribute__((swift_name("Unlimited")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ContentConverterException")))
@interface MDTMContentConverterException : MDTMKotlinException
- (instancetype)initWithMessage:(NSString *)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((swift_name("Ktor_serializationConfiguration")))
@protocol MDTMKtor_serializationConfiguration
@required
- (void)registerContentType:(MDTMKtor_httpContentType *)contentType converter:(id<MDTMKtor_serializationContentConverter>)converter configuration:(void (^)(id<MDTMKtor_serializationContentConverter>))configuration __attribute__((swift_name("register(contentType:converter:configuration:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ContentNegotiationConfig")))
@interface MDTMContentNegotiationConfig : MDTMBase <MDTMKtor_serializationConfiguration>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)clearIgnoredTypes __attribute__((swift_name("clearIgnoredTypes()")));
- (void)ignoreType __attribute__((swift_name("ignoreType()")));
- (void)ignoreTypeType:(id<MDTMKotlinKClass>)type __attribute__((swift_name("ignoreType(type:)")));
- (void)registerContentType:(MDTMKtor_httpContentType *)contentType converter:(id<MDTMKtor_serializationContentConverter>)converter configuration:(void (^)(id<MDTMKtor_serializationContentConverter>))configuration __attribute__((swift_name("register(contentType:converter:configuration:)")));
- (void)registerContentTypeToSend:(MDTMKtor_httpContentType *)contentTypeToSend converter:(id<MDTMKtor_serializationContentConverter>)converter contentTypeMatcher:(id<MDTMKtor_httpContentTypeMatcher>)contentTypeMatcher configuration:(void (^)(id<MDTMKtor_serializationContentConverter>))configuration __attribute__((swift_name("register(contentTypeToSend:converter:contentTypeMatcher:configuration:)")));
- (void)removeIgnoredType __attribute__((swift_name("removeIgnoredType()")));
- (void)removeIgnoredTypeType:(id<MDTMKotlinKClass>)type __attribute__((swift_name("removeIgnoredType(type:)")));
@property MDTMDouble * _Nullable defaultAcceptHeaderQValue __attribute__((swift_name("defaultAcceptHeaderQValue")));
@end

__attribute__((swift_name("Ktor_httpContentTypeMatcher")))
@protocol MDTMKtor_httpContentTypeMatcher
@required
- (BOOL)containsContentType:(MDTMKtor_httpContentType *)contentType __attribute__((swift_name("contains(contentType:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("JsonContentTypeMatcher")))
@interface MDTMJsonContentTypeMatcher : MDTMBase <MDTMKtor_httpContentTypeMatcher>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)jsonContentTypeMatcher __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMJsonContentTypeMatcher *shared __attribute__((swift_name("shared")));
- (BOOL)containsContentType:(MDTMKtor_httpContentType *)contentType __attribute__((swift_name("contains(contentType:)")));
@end

__attribute__((swift_name("CookiesStorage")))
@protocol MDTMCookiesStorage <MDTMKtor_ioCloseable>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)addCookieRequestUrl:(MDTMKtor_httpUrl *)requestUrl cookie:(MDTMKtor_httpCookie *)cookie completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("addCookie(requestUrl:cookie:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getRequestUrl:(MDTMKtor_httpUrl *)requestUrl completionHandler:(void (^)(NSArray<MDTMKtor_httpCookie *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("get(requestUrl:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AcceptAllCookiesStorage")))
@interface MDTMAcceptAllCookiesStorage : MDTMBase <MDTMCookiesStorage>
- (instancetype)initWithClock:(MDTMLong *(^)(void))clock __attribute__((swift_name("init(clock:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)addCookieRequestUrl:(MDTMKtor_httpUrl *)requestUrl cookie:(MDTMKtor_httpCookie *)cookie completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("addCookie(requestUrl:cookie:completionHandler:)")));
- (void)close __attribute__((swift_name("close()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getRequestUrl:(MDTMKtor_httpUrl *)requestUrl completionHandler:(void (^)(NSArray<MDTMKtor_httpCookie *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("get(requestUrl:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConstantCookiesStorage")))
@interface MDTMConstantCookiesStorage : MDTMBase <MDTMCookiesStorage>
- (instancetype)initWithCookies:(MDTMKotlinArray<MDTMKtor_httpCookie *> *)cookies __attribute__((swift_name("init(cookies:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)addCookieRequestUrl:(MDTMKtor_httpUrl *)requestUrl cookie:(MDTMKtor_httpCookie *)cookie completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("addCookie(requestUrl:cookie:completionHandler:)")));
- (void)close __attribute__((swift_name("close()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getRequestUrl:(MDTMKtor_httpUrl *)requestUrl completionHandler:(void (^)(NSArray<MDTMKtor_httpCookie *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("get(requestUrl:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpCookies")))
@interface MDTMHttpCookies : MDTMBase <MDTMKtor_ioCloseable>
@property (class, readonly, getter=companion) MDTMHttpCookiesCompanion *companion __attribute__((swift_name("companion")));
- (void)close __attribute__((swift_name("close()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getRequestUrl:(MDTMKtor_httpUrl *)requestUrl completionHandler:(void (^)(NSArray<MDTMKtor_httpCookie *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("get(requestUrl:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpCookies.Companion")))
@interface MDTMHttpCookiesCompanion : MDTMBase <MDTMHttpClientPlugin>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMHttpCookiesCompanion *shared __attribute__((swift_name("shared")));
- (void)installPlugin:(MDTMHttpCookies *)plugin scope:(MDTMHttpClient *)scope __attribute__((swift_name("install(plugin:scope:)")));
- (MDTMHttpCookies *)prepareBlock:(void (^)(MDTMHttpCookiesConfig *))block __attribute__((swift_name("prepare(block:)")));
@property (readonly) MDTMKtor_utilsAttributeKey<MDTMHttpCookies *> *key __attribute__((swift_name("key")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpCookies.Config")))
@interface MDTMHttpCookiesConfig : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)defaultBlock:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("default(block:)")));
@property id<MDTMCookiesStorage> storage __attribute__((swift_name("storage")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SaveBodyAbandonedReadException")))
@interface MDTMSaveBodyAbandonedReadException : MDTMKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("This exception is deprecated and is never thrown")));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ResponseObserverConfig")))
@interface MDTMResponseObserverConfig : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)filterBlock:(MDTMBoolean *(^)(MDTMHttpClientCall *))block __attribute__((swift_name("filter(block:)")));
- (void)onResponseBlock:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("onResponse(block:)")));
@end

__attribute__((swift_name("SSESession")))
@protocol MDTMSSESession <MDTMCoroutineScope>
@required
@property (readonly) id<MDTMFlow> incoming __attribute__((swift_name("incoming")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ClientSSESession")))
@interface MDTMClientSSESession : MDTMBase <MDTMSSESession>
- (instancetype)initWithCall:(MDTMHttpClientCall *)call delegate:(id<MDTMSSESession>)delegate __attribute__((swift_name("init(call:delegate:)"))) __attribute__((objc_designated_initializer));
@property (readonly) MDTMHttpClientCall *call __attribute__((swift_name("call")));
@property (readonly) id<MDTMKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property (readonly) id<MDTMFlow> incoming __attribute__((swift_name("incoming")));
@end

__attribute__((swift_name("SSESessionWithDeserialization")))
@protocol MDTMSSESessionWithDeserialization <MDTMCoroutineScope>
@required
@property (readonly) id _Nullable (^deserializer)(MDTMKtor_utilsTypeInfo *, NSString *) __attribute__((swift_name("deserializer")));
@property (readonly) id<MDTMFlow> incoming __attribute__((swift_name("incoming")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ClientSSESessionWithDeserialization")))
@interface MDTMClientSSESessionWithDeserialization : MDTMBase <MDTMSSESessionWithDeserialization>
- (instancetype)initWithCall:(MDTMHttpClientCall *)call delegate:(id<MDTMSSESessionWithDeserialization>)delegate __attribute__((swift_name("init(call:delegate:)"))) __attribute__((objc_designated_initializer));
@property (readonly) MDTMHttpClientCall *call __attribute__((swift_name("call")));
@property (readonly) id<MDTMKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property (readonly) id _Nullable (^deserializer)(MDTMKtor_utilsTypeInfo *, NSString *) __attribute__((swift_name("deserializer")));
@property (readonly) id<MDTMFlow> incoming __attribute__((swift_name("incoming")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DefaultClientSSESession")))
@interface MDTMDefaultClientSSESession : MDTMBase <MDTMSSESession>
- (instancetype)initWithContent:(MDTMSSEClientContent *)content input:(id<MDTMKtor_ioByteReadChannel>)input __attribute__((swift_name("init(content:input:)"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("It should be marked with `@InternalAPI`, please use `ClientSSESession` instead")));
- (instancetype)initWithContent:(MDTMSSEClientContent *)content input:(id<MDTMKtor_ioByteReadChannel>)input coroutineContext:(id<MDTMKotlinCoroutineContext>)coroutineContext __attribute__((swift_name("init(content:input:coroutineContext:)"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("It should be marked with `@InternalAPI`, please use `ClientSSESession` instead")));
@property (readonly) id<MDTMKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property (readonly) id<MDTMFlow> incoming __attribute__((swift_name("incoming")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SSECapability")))
@interface MDTMSSECapability : MDTMBase <MDTMHttpClientEngineCapability>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)sSECapability __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMSSECapability *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Ktor_httpOutgoingContent")))
@interface MDTMKtor_httpOutgoingContent : MDTMBase
- (id _Nullable)getPropertyKey:(MDTMKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("getProperty(key:)")));
- (void)setPropertyKey:(MDTMKtor_utilsAttributeKey<id> *)key value:(id _Nullable)value __attribute__((swift_name("setProperty(key:value:)")));
- (id<MDTMKtor_httpHeaders> _Nullable)trailers __attribute__((swift_name("trailers()")));
@property (readonly) MDTMLong * _Nullable contentLength __attribute__((swift_name("contentLength")));
@property (readonly) MDTMKtor_httpContentType * _Nullable contentType __attribute__((swift_name("contentType")));
@property (readonly) id<MDTMKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) MDTMKtor_httpHttpStatusCode * _Nullable status __attribute__((swift_name("status")));
@end

__attribute__((swift_name("Ktor_httpOutgoingContent.ContentWrapper")))
@interface MDTMKtor_httpOutgoingContentContentWrapper : MDTMKtor_httpOutgoingContent
- (instancetype)initWithDelegate:(MDTMKtor_httpOutgoingContent *)delegate __attribute__((swift_name("init(delegate:)"))) __attribute__((objc_designated_initializer));
- (MDTMKtor_httpOutgoingContentContentWrapper *)doCopyDelegate:(MDTMKtor_httpOutgoingContent *)delegate __attribute__((swift_name("doCopy(delegate:)")));
- (MDTMKtor_httpOutgoingContent *)delegate __attribute__((swift_name("delegate()")));
- (id _Nullable)getPropertyKey:(MDTMKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("getProperty(key:)")));
- (void)setPropertyKey:(MDTMKtor_utilsAttributeKey<id> *)key value:(id _Nullable)value __attribute__((swift_name("setProperty(key:value:)")));
@property (readonly) MDTMLong * _Nullable contentLength __attribute__((swift_name("contentLength")));
@property (readonly) MDTMKtor_httpContentType * _Nullable contentType __attribute__((swift_name("contentType")));
@property (readonly) id<MDTMKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) MDTMKtor_httpHttpStatusCode * _Nullable status __attribute__((swift_name("status")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SSEClientContent")))
@interface MDTMSSEClientContent : MDTMKtor_httpOutgoingContentContentWrapper
- (instancetype)initWithReconnectionTime:(int64_t)reconnectionTime showCommentEvents:(BOOL)showCommentEvents showRetryEvents:(BOOL)showRetryEvents maxReconnectionAttempts:(int32_t)maxReconnectionAttempts callContext:(id<MDTMKotlinCoroutineContext>)callContext initialRequest:(MDTMHttpRequestBuilder *)initialRequest requestBody:(MDTMKtor_httpOutgoingContent *)requestBody __attribute__((swift_name("init(reconnectionTime:showCommentEvents:showRetryEvents:maxReconnectionAttempts:callContext:initialRequest:requestBody:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithDelegate:(MDTMKtor_httpOutgoingContent *)delegate __attribute__((swift_name("init(delegate:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (MDTMSSEClientContent *)doCopyDelegate:(MDTMKtor_httpOutgoingContent *)delegate __attribute__((swift_name("doCopy(delegate:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<MDTMKotlinCoroutineContext> callContext __attribute__((swift_name("callContext")));
@property (readonly) id<MDTMKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) MDTMHttpRequestBuilder *initialRequest __attribute__((swift_name("initialRequest")));
@property (readonly) int32_t maxReconnectionAttempts __attribute__((swift_name("maxReconnectionAttempts")));
@property (readonly) int64_t reconnectionTime __attribute__((swift_name("reconnectionTime")));
@property (readonly) BOOL showCommentEvents __attribute__((swift_name("showCommentEvents")));
@property (readonly) BOOL showRetryEvents __attribute__((swift_name("showRetryEvents")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SSEClientException")))
@interface MDTMSSEClientException : MDTMKotlinIllegalStateException
- (instancetype)initWithResponse:(MDTMHttpResponse * _Nullable)response cause:(MDTMKotlinThrowable * _Nullable)cause message:(NSString * _Nullable)message __attribute__((swift_name("init(response:cause:message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) MDTMKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
@property (readonly) MDTMHttpResponse * _Nullable response __attribute__((swift_name("response")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SSEConfig")))
@interface MDTMSSEConfig : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)showCommentEvents __attribute__((swift_name("showCommentEvents()")));
- (void)showRetryEvents __attribute__((swift_name("showRetryEvents()")));
@property int32_t maxReconnectionAttempts __attribute__((swift_name("maxReconnectionAttempts")));
@property int64_t reconnectionTime __attribute__((swift_name("reconnectionTime")));
@end

__attribute__((swift_name("Ktor_websocketsWebSocketSession")))
@protocol MDTMKtor_websocketsWebSocketSession <MDTMCoroutineScope>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)flushWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("flush(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sendFrame:(MDTMKtor_websocketsFrame *)frame completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("send(frame:completionHandler:)")));
- (void)terminate __attribute__((swift_name("terminate()"))) __attribute__((unavailable("Use cancel() instead.")));
@property (readonly) NSArray<id<MDTMKtor_websocketsWebSocketExtension>> *extensions __attribute__((swift_name("extensions")));
@property (readonly) id<MDTMReceiveChannel> incoming __attribute__((swift_name("incoming")));
@property BOOL masking __attribute__((swift_name("masking")));
@property int64_t maxFrameSize __attribute__((swift_name("maxFrameSize")));
@property (readonly) id<MDTMSendChannel> outgoing __attribute__((swift_name("outgoing")));
@end

__attribute__((swift_name("ClientWebSocketSession")))
@protocol MDTMClientWebSocketSession <MDTMKtor_websocketsWebSocketSession>
@required
@property (readonly) MDTMHttpClientCall *call __attribute__((swift_name("call")));
@end

__attribute__((swift_name("Ktor_websocketsDefaultWebSocketSession")))
@protocol MDTMKtor_websocketsDefaultWebSocketSession <MDTMKtor_websocketsWebSocketSession>
@required
- (void)startNegotiatedExtensions:(NSArray<id<MDTMKtor_websocketsWebSocketExtension>> *)negotiatedExtensions __attribute__((swift_name("start(negotiatedExtensions:)")));
@property (readonly) id<MDTMDeferred> closeReason __attribute__((swift_name("closeReason")));
@property int64_t pingIntervalMillis __attribute__((swift_name("pingIntervalMillis")));
@property int64_t timeoutMillis __attribute__((swift_name("timeoutMillis")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DefaultClientWebSocketSession")))
@interface MDTMDefaultClientWebSocketSession : MDTMBase <MDTMClientWebSocketSession, MDTMKtor_websocketsDefaultWebSocketSession>
- (instancetype)initWithCall:(MDTMHttpClientCall *)call delegate:(id<MDTMKtor_websocketsDefaultWebSocketSession>)delegate __attribute__((swift_name("init(call:delegate:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)flushWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("flush(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sendFrame:(MDTMKtor_websocketsFrame *)frame completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("send(frame:completionHandler:)")));
- (void)startNegotiatedExtensions:(NSArray<id<MDTMKtor_websocketsWebSocketExtension>> *)negotiatedExtensions __attribute__((swift_name("start(negotiatedExtensions:)")));
- (void)terminate __attribute__((swift_name("terminate()"))) __attribute__((unavailable("Use cancel() instead.")));
@property (readonly) MDTMHttpClientCall *call __attribute__((swift_name("call")));
@property (readonly) id<MDTMDeferred> closeReason __attribute__((swift_name("closeReason")));
@property (readonly) id<MDTMKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property (readonly) NSArray<id<MDTMKtor_websocketsWebSocketExtension>> *extensions __attribute__((swift_name("extensions")));
@property (readonly) id<MDTMReceiveChannel> incoming __attribute__((swift_name("incoming")));
@property BOOL masking __attribute__((swift_name("masking")));
@property int64_t maxFrameSize __attribute__((swift_name("maxFrameSize")));
@property (readonly) id<MDTMSendChannel> outgoing __attribute__((swift_name("outgoing")));
@property int64_t pingIntervalMillis __attribute__((swift_name("pingIntervalMillis")));
@property int64_t timeoutMillis __attribute__((swift_name("timeoutMillis")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("WebSocketCapability")))
@interface MDTMWebSocketCapability : MDTMBase <MDTMHttpClientEngineCapability>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)webSocketCapability __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMWebSocketCapability *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("WebSocketException")))
@interface MDTMWebSocketException : MDTMKotlinIllegalStateException
- (instancetype)initWithMessage:(NSString *)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString *)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("WebSocketExtensionsCapability")))
@interface MDTMWebSocketExtensionsCapability : MDTMBase <MDTMHttpClientEngineCapability>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)webSocketExtensionsCapability __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMWebSocketExtensionsCapability *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("WebSockets")))
@interface MDTMWebSockets : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithPingIntervalMillis:(int64_t)pingIntervalMillis maxFrameSize:(int64_t)maxFrameSize __attribute__((swift_name("init(pingIntervalMillis:maxFrameSize:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMWebSocketsPlugin *companion __attribute__((swift_name("companion")));
@property (readonly) id<MDTMKtor_serializationWebsocketContentConverter> _Nullable contentConverter __attribute__((swift_name("contentConverter")));
@property (readonly) int64_t maxFrameSize __attribute__((swift_name("maxFrameSize")));
@property (readonly) int64_t pingIntervalMillis __attribute__((swift_name("pingIntervalMillis")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("WebSockets.Config")))
@interface MDTMWebSocketsConfig : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)extensionsBlock:(void (^)(MDTMKtor_websocketsWebSocketExtensionsConfig *))block __attribute__((swift_name("extensions(block:)")));
@property id<MDTMKtor_serializationWebsocketContentConverter> _Nullable contentConverter __attribute__((swift_name("contentConverter")));
@property int64_t maxFrameSize __attribute__((swift_name("maxFrameSize")));
@property int64_t pingIntervalMillis __attribute__((swift_name("pingIntervalMillis")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("WebSockets.Plugin")))
@interface MDTMWebSocketsPlugin : MDTMBase <MDTMHttpClientPlugin>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)plugin __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMWebSocketsPlugin *shared __attribute__((swift_name("shared")));
- (void)installPlugin:(MDTMWebSockets *)plugin scope:(MDTMHttpClient *)scope __attribute__((swift_name("install(plugin:scope:)")));
- (MDTMWebSockets *)prepareBlock:(void (^)(MDTMWebSocketsConfig *))block __attribute__((swift_name("prepare(block:)")));
@property (readonly) MDTMKtor_utilsAttributeKey<MDTMWebSockets *> *key __attribute__((swift_name("key")));
@end

__attribute__((swift_name("Ktor_httpOutgoingContent.NoContent")))
@interface MDTMKtor_httpOutgoingContentNoContent : MDTMKtor_httpOutgoingContent
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@end

__attribute__((swift_name("ClientUpgradeContent")))
@interface MDTMClientUpgradeContent : MDTMKtor_httpOutgoingContentNoContent
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)pipeToOutput:(id<MDTMKtor_ioByteWriteChannel>)output completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("pipeTo(output:completionHandler:)")));
- (void)verifyHeaders:(id<MDTMKtor_httpHeaders>)headers __attribute__((swift_name("verify(headers:)")));
@property (readonly) id<MDTMKtor_ioByteWriteChannel> output __attribute__((swift_name("output")));
@end

__attribute__((swift_name("Ktor_httpHttpMessage")))
@protocol MDTMKtor_httpHttpMessage
@required
@property (readonly) id<MDTMKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@end

__attribute__((swift_name("HttpRequest")))
@protocol MDTMHttpRequest <MDTMKtor_httpHttpMessage, MDTMCoroutineScope>
@required
@property (readonly) id<MDTMKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) MDTMHttpClientCall *call __attribute__((swift_name("call")));
@property (readonly) MDTMKtor_httpOutgoingContent *content __attribute__((swift_name("content")));
@property (readonly) MDTMKtor_httpHttpMethod *method __attribute__((swift_name("method")));
@property (readonly) MDTMKtor_httpUrl *url __attribute__((swift_name("url")));
@end

__attribute__((swift_name("DefaultHttpRequest")))
@interface MDTMDefaultHttpRequest : MDTMBase <MDTMHttpRequest>
- (instancetype)initWithCall:(MDTMHttpClientCall *)call data:(MDTMHttpRequestData *)data __attribute__((swift_name("init(call:data:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id<MDTMKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) MDTMHttpClientCall *call __attribute__((swift_name("call")));
@property (readonly) MDTMKtor_httpOutgoingContent *content __attribute__((swift_name("content")));
@property (readonly) id<MDTMKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property (readonly) id<MDTMKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) MDTMKtor_httpHttpMethod *method __attribute__((swift_name("method")));
@property (readonly) MDTMKtor_httpUrl *url __attribute__((swift_name("url")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRequestBuilder")))
@interface MDTMHttpRequestBuilder : MDTMBase <MDTMKtor_httpHttpMessageBuilder>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) MDTMHttpRequestBuilderCompanion *companion __attribute__((swift_name("companion")));
- (MDTMHttpRequestData *)build __attribute__((swift_name("build()")));
- (id _Nullable)getCapabilityOrNullKey:(id<MDTMHttpClientEngineCapability>)key __attribute__((swift_name("getCapabilityOrNull(key:)")));
- (void)setAttributesBlock:(void (^)(id<MDTMKtor_utilsAttributes>))block __attribute__((swift_name("setAttributes(block:)")));
- (void)setCapabilityKey:(id<MDTMHttpClientEngineCapability>)key capability:(id)capability __attribute__((swift_name("setCapability(key:capability:)")));
- (MDTMHttpRequestBuilder *)takeFromBuilder:(MDTMHttpRequestBuilder *)builder __attribute__((swift_name("takeFrom(builder:)")));
- (MDTMHttpRequestBuilder *)takeFromWithExecutionContextBuilder:(MDTMHttpRequestBuilder *)builder __attribute__((swift_name("takeFromWithExecutionContext(builder:)")));
- (void)urlBlock:(void (^)(MDTMKtor_httpURLBuilder *, MDTMKtor_httpURLBuilder *))block __attribute__((swift_name("url(block:)")));
@property (readonly) id<MDTMKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property id body __attribute__((swift_name("body")));
@property MDTMKtor_utilsTypeInfo * _Nullable bodyType __attribute__((swift_name("bodyType")));
@property (readonly) id<MDTMJob> executionContext __attribute__((swift_name("executionContext")));
@property (readonly) MDTMKtor_httpHeadersBuilder *headers __attribute__((swift_name("headers")));
@property MDTMKtor_httpHttpMethod *method __attribute__((swift_name("method")));
@property (readonly) MDTMKtor_httpURLBuilder *url __attribute__((swift_name("url")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRequestBuilder.Companion")))
@interface MDTMHttpRequestBuilderCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMHttpRequestBuilderCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRequestData")))
@interface MDTMHttpRequestData : MDTMBase
- (instancetype)initWithUrl:(MDTMKtor_httpUrl *)url method:(MDTMKtor_httpHttpMethod *)method headers:(id<MDTMKtor_httpHeaders>)headers body:(MDTMKtor_httpOutgoingContent *)body executionContext:(id<MDTMJob>)executionContext attributes:(id<MDTMKtor_utilsAttributes>)attributes __attribute__((swift_name("init(url:method:headers:body:executionContext:attributes:)"))) __attribute__((objc_designated_initializer));
- (id _Nullable)getCapabilityOrNullKey:(id<MDTMHttpClientEngineCapability>)key __attribute__((swift_name("getCapabilityOrNull(key:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<MDTMKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) MDTMKtor_httpOutgoingContent *body __attribute__((swift_name("body")));
@property (readonly) id<MDTMJob> executionContext __attribute__((swift_name("executionContext")));
@property (readonly) id<MDTMKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) MDTMKtor_httpHttpMethod *method __attribute__((swift_name("method")));
@property (readonly) MDTMKtor_httpUrl *url __attribute__((swift_name("url")));
@end

__attribute__((swift_name("Ktor_utilsPipeline")))
@interface MDTMKtor_utilsPipeline<TSubject, TContext> : MDTMBase
- (instancetype)initWithPhases:(MDTMKotlinArray<MDTMKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhase:(MDTMKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<MDTMKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer));
- (void)addPhasePhase:(MDTMKtor_utilsPipelinePhase *)phase __attribute__((swift_name("addPhase(phase:)")));
- (void)afterIntercepted __attribute__((swift_name("afterIntercepted()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)executeContext:(TContext)context subject:(TSubject)subject completionHandler:(void (^)(TSubject _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("execute(context:subject:completionHandler:)")));
- (void)insertPhaseAfterReference:(MDTMKtor_utilsPipelinePhase *)reference phase:(MDTMKtor_utilsPipelinePhase *)phase __attribute__((swift_name("insertPhaseAfter(reference:phase:)")));
- (void)insertPhaseBeforeReference:(MDTMKtor_utilsPipelinePhase *)reference phase:(MDTMKtor_utilsPipelinePhase *)phase __attribute__((swift_name("insertPhaseBefore(reference:phase:)")));
- (void)interceptPhase:(MDTMKtor_utilsPipelinePhase *)phase block:(id<MDTMKotlinSuspendFunction2>)block __attribute__((swift_name("intercept(phase:block:)")));
- (NSArray<id<MDTMKotlinSuspendFunction2>> *)interceptorsForPhasePhase:(MDTMKtor_utilsPipelinePhase *)phase __attribute__((swift_name("interceptorsForPhase(phase:)")));
- (void)mergeFrom:(MDTMKtor_utilsPipeline<TSubject, TContext> *)from __attribute__((swift_name("merge(from:)")));
- (void)mergePhasesFrom:(MDTMKtor_utilsPipeline<TSubject, TContext> *)from __attribute__((swift_name("mergePhases(from:)")));
- (void)resetFromFrom:(MDTMKtor_utilsPipeline<TSubject, TContext> *)from __attribute__((swift_name("resetFrom(from:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<MDTMKtor_utilsAttributes> attributes __attribute__((swift_name("attributes")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@property (readonly) BOOL isEmpty __attribute__((swift_name("isEmpty")));
@property (readonly) NSArray<MDTMKtor_utilsPipelinePhase *> *items __attribute__((swift_name("items")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRequestPipeline")))
@interface MDTMHttpRequestPipeline : MDTMKtor_utilsPipeline<id, MDTMHttpRequestBuilder *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(MDTMKotlinArray<MDTMKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(MDTMKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<MDTMKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) MDTMHttpRequestPipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRequestPipeline.Phases")))
@interface MDTMHttpRequestPipelinePhases : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMHttpRequestPipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) MDTMKtor_utilsPipelinePhase *Before __attribute__((swift_name("Before")));
@property (readonly) MDTMKtor_utilsPipelinePhase *Render __attribute__((swift_name("Render")));
@property (readonly) MDTMKtor_utilsPipelinePhase *Send __attribute__((swift_name("Send")));
@property (readonly) MDTMKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@property (readonly) MDTMKtor_utilsPipelinePhase *Transform __attribute__((swift_name("Transform")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpResponseData")))
@interface MDTMHttpResponseData : MDTMBase
- (instancetype)initWithStatusCode:(MDTMKtor_httpHttpStatusCode *)statusCode requestTime:(MDTMKtor_utilsGMTDate *)requestTime headers:(id<MDTMKtor_httpHeaders>)headers version:(MDTMKtor_httpHttpProtocolVersion *)version body:(id)body callContext:(id<MDTMKotlinCoroutineContext>)callContext __attribute__((swift_name("init(statusCode:requestTime:headers:version:body:callContext:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id body __attribute__((swift_name("body")));
@property (readonly) id<MDTMKotlinCoroutineContext> callContext __attribute__((swift_name("callContext")));
@property (readonly) id<MDTMKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) MDTMKtor_utilsGMTDate *requestTime __attribute__((swift_name("requestTime")));
@property (readonly) MDTMKtor_utilsGMTDate *responseTime __attribute__((swift_name("responseTime")));
@property (readonly) MDTMKtor_httpHttpStatusCode *statusCode __attribute__((swift_name("statusCode")));
@property (readonly) MDTMKtor_httpHttpProtocolVersion *version __attribute__((swift_name("version")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpSendPipeline")))
@interface MDTMHttpSendPipeline : MDTMKtor_utilsPipeline<id, MDTMHttpRequestBuilder *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(MDTMKotlinArray<MDTMKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(MDTMKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<MDTMKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) MDTMHttpSendPipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpSendPipeline.Phases")))
@interface MDTMHttpSendPipelinePhases : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMHttpSendPipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) MDTMKtor_utilsPipelinePhase *Before __attribute__((swift_name("Before")));
@property (readonly) MDTMKtor_utilsPipelinePhase *Engine __attribute__((swift_name("Engine")));
@property (readonly) MDTMKtor_utilsPipelinePhase *Monitoring __attribute__((swift_name("Monitoring")));
@property (readonly) MDTMKtor_utilsPipelinePhase *Receive __attribute__((swift_name("Receive")));
@property (readonly) MDTMKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@end

__attribute__((swift_name("ResponseAdapter")))
@protocol MDTMResponseAdapter
@required
- (id _Nullable)adaptData:(MDTMHttpRequestData *)data status:(MDTMKtor_httpHttpStatusCode *)status headers:(id<MDTMKtor_httpHeaders>)headers responseBody:(id<MDTMKtor_ioByteReadChannel>)responseBody outgoingContent:(MDTMKtor_httpOutgoingContent *)outgoingContent callContext:(id<MDTMKotlinCoroutineContext>)callContext __attribute__((swift_name("adapt(data:status:headers:responseBody:outgoingContent:callContext:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SSEClientResponseAdapter")))
@interface MDTMSSEClientResponseAdapter : MDTMBase <MDTMResponseAdapter>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (id _Nullable)adaptData:(MDTMHttpRequestData *)data status:(MDTMKtor_httpHttpStatusCode *)status headers:(id<MDTMKtor_httpHeaders>)headers responseBody:(id<MDTMKtor_ioByteReadChannel>)responseBody outgoingContent:(MDTMKtor_httpOutgoingContent *)outgoingContent callContext:(id<MDTMKotlinCoroutineContext>)callContext __attribute__((swift_name("adapt(data:status:headers:responseBody:outgoingContent:callContext:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UnixSocketCapability")))
@interface MDTMUnixSocketCapability : MDTMBase <MDTMHttpClientEngineCapability>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)unixSocketCapability __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMUnixSocketCapability *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UnixSocketSettings")))
@interface MDTMUnixSocketSettings : MDTMBase
- (instancetype)initWithPath:(NSString *)path __attribute__((swift_name("init(path:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSString *path __attribute__((swift_name("path")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChannelProvider")))
@interface MDTMChannelProvider : MDTMBase
- (instancetype)initWithSize:(MDTMLong * _Nullable)size block:(id<MDTMKtor_ioByteReadChannel> (^)(void))block __attribute__((swift_name("init(size:block:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id<MDTMKtor_ioByteReadChannel> (^block)(void) __attribute__((swift_name("block")));
@property (readonly) MDTMLong * _Nullable size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FormBuilder")))
@interface MDTMFormBuilder : MDTMBase
- (void)appendPart:(MDTMFormPart<id> *)part __attribute__((swift_name("append(part:)")));
- (void)appendKey:(NSString *)key value:(id)value headers:(id<MDTMKtor_httpHeaders>)headers __attribute__((swift_name("append(key:value:headers:)")));
- (void)appendKey:(NSString *)key value:(MDTMChannelProvider *)value headers_:(id<MDTMKtor_httpHeaders>)headers __attribute__((swift_name("append(key:value:headers_:)")));
- (void)appendKey:(NSString *)key value:(MDTMInputProvider *)value headers__:(id<MDTMKtor_httpHeaders>)headers __attribute__((swift_name("append(key:value:headers__:)")));
- (void)appendKey:(NSString *)key values:(MDTMKotlinArray<NSString *> *)values headers:(id<MDTMKtor_httpHeaders>)headers __attribute__((swift_name("append(key:values:headers:)")));
- (void)appendKey:(NSString *)key value:(BOOL)value headers___:(id<MDTMKtor_httpHeaders>)headers __attribute__((swift_name("append(key:value:headers___:)")));
- (void)appendKey:(NSString *)key value:(MDTMKotlinByteArray *)value headers____:(id<MDTMKtor_httpHeaders>)headers __attribute__((swift_name("append(key:value:headers____:)")));
- (void)appendKey:(NSString *)key value:(id)value headers_____:(id<MDTMKtor_httpHeaders>)headers __attribute__((swift_name("append(key:value:headers_____:)")));
- (void)appendKey:(NSString *)key value:(NSString *)value headers______:(id<MDTMKtor_httpHeaders>)headers __attribute__((swift_name("append(key:value:headers______:)")));
- (void)appendKey:(NSString *)key values:(id)values headers_:(id<MDTMKtor_httpHeaders>)headers __attribute__((swift_name("append(key:values:headers_:)")));
- (void)appendKey:(NSString *)key value:(id<MDTMKotlinx_io_coreSource>)value headers_______:(id<MDTMKtor_httpHeaders>)headers __attribute__((swift_name("append(key:value:headers_______:)")));
- (void)appendInputKey:(NSString *)key headers:(id<MDTMKtor_httpHeaders>)headers size:(MDTMLong * _Nullable)size block:(id<MDTMKotlinx_io_coreSource> (^)(void))block __attribute__((swift_name("appendInput(key:headers:size:block:)")));
@end

__attribute__((swift_name("Ktor_httpOutgoingContent.ByteArrayContent")))
@interface MDTMKtor_httpOutgoingContentByteArrayContent : MDTMKtor_httpOutgoingContent
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (MDTMKotlinByteArray *)bytes __attribute__((swift_name("bytes()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FormDataContent")))
@interface MDTMFormDataContent : MDTMKtor_httpOutgoingContentByteArrayContent
- (instancetype)initWithFormData:(id<MDTMKtor_httpParameters>)formData __attribute__((swift_name("init(formData:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (MDTMKotlinByteArray *)bytes __attribute__((swift_name("bytes()")));
@property (readonly) MDTMLong *contentLength __attribute__((swift_name("contentLength")));
@property (readonly) MDTMKtor_httpContentType *contentType __attribute__((swift_name("contentType")));
@property (readonly) id<MDTMKtor_httpParameters> formData __attribute__((swift_name("formData")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FormPart")))
@interface MDTMFormPart<T> : MDTMBase
- (instancetype)initWithKey:(NSString *)key value:(T)value headers:(id<MDTMKtor_httpHeaders>)headers __attribute__((swift_name("init(key:value:headers:)"))) __attribute__((objc_designated_initializer));
- (MDTMFormPart<T> *)doCopyKey:(NSString *)key value:(T)value headers:(id<MDTMKtor_httpHeaders>)headers __attribute__((swift_name("doCopy(key:value:headers:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<MDTMKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) NSString *key __attribute__((swift_name("key")));
@property (readonly) T value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("InputProvider")))
@interface MDTMInputProvider : MDTMBase
- (instancetype)initWithSize:(MDTMLong * _Nullable)size block:(id<MDTMKotlinx_io_coreSource> (^)(void))block __attribute__((swift_name("init(size:block:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id<MDTMKotlinx_io_coreSource> (^block)(void) __attribute__((swift_name("block")));
@property (readonly) MDTMLong * _Nullable size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("Ktor_httpOutgoingContent.WriteChannelContent")))
@interface MDTMKtor_httpOutgoingContentWriteChannelContent : MDTMKtor_httpOutgoingContent
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)writeToChannel:(id<MDTMKtor_ioByteWriteChannel>)channel completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("writeTo(channel:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MultiPartFormDataContent")))
@interface MDTMMultiPartFormDataContent : MDTMKtor_httpOutgoingContentWriteChannelContent
- (instancetype)initWithParts:(NSArray<MDTMKtor_httpPartData *> *)parts boundary:(NSString *)boundary contentType:(MDTMKtor_httpContentType *)contentType __attribute__((swift_name("init(parts:boundary:contentType:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)writeToChannel:(id<MDTMKtor_ioByteWriteChannel>)channel completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("writeTo(channel:completionHandler:)")));
@property (readonly) NSString *boundary __attribute__((swift_name("boundary")));
@property (readonly) MDTMLong * _Nullable contentLength __attribute__((swift_name("contentLength")));
@property (readonly) MDTMKtor_httpContentType *contentType __attribute__((swift_name("contentType")));
@end

__attribute__((swift_name("HttpResponse")))
@interface MDTMHttpResponse : MDTMBase <MDTMKtor_httpHttpMessage, MDTMCoroutineScope>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) MDTMHttpClientCall *call __attribute__((swift_name("call")));
@property (readonly) id<MDTMKtor_ioByteReadChannel> rawContent __attribute__((swift_name("rawContent")));
@property (readonly) MDTMKtor_utilsGMTDate *requestTime __attribute__((swift_name("requestTime")));
@property (readonly) MDTMKtor_utilsGMTDate *responseTime __attribute__((swift_name("responseTime")));
@property (readonly) MDTMKtor_httpHttpStatusCode *status __attribute__((swift_name("status")));
@property (readonly) MDTMKtor_httpHttpProtocolVersion *version __attribute__((swift_name("version")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DefaultHttpResponse")))
@interface MDTMDefaultHttpResponse : MDTMHttpResponse
- (instancetype)initWithCall:(MDTMHttpClientCall *)call responseData:(MDTMHttpResponseData *)responseData __attribute__((swift_name("init(call:responseData:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
@property (readonly) MDTMHttpClientCall *call __attribute__((swift_name("call")));
@property (readonly) id<MDTMKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property (readonly) id<MDTMKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) id<MDTMKtor_ioByteReadChannel> rawContent __attribute__((swift_name("rawContent")));
@property (readonly) MDTMKtor_utilsGMTDate *requestTime __attribute__((swift_name("requestTime")));
@property (readonly) MDTMKtor_utilsGMTDate *responseTime __attribute__((swift_name("responseTime")));
@property (readonly) MDTMKtor_httpHttpStatusCode *status __attribute__((swift_name("status")));
@property (readonly) MDTMKtor_httpHttpProtocolVersion *version __attribute__((swift_name("version")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpReceivePipeline")))
@interface MDTMHttpReceivePipeline : MDTMKtor_utilsPipeline<MDTMHttpResponse *, MDTMKotlinUnit *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(MDTMKotlinArray<MDTMKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(MDTMKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<MDTMKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) MDTMHttpReceivePipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpReceivePipeline.Phases")))
@interface MDTMHttpReceivePipelinePhases : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMHttpReceivePipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) MDTMKtor_utilsPipelinePhase *After __attribute__((swift_name("After")));
@property (readonly) MDTMKtor_utilsPipelinePhase *Before __attribute__((swift_name("Before")));
@property (readonly) MDTMKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpResponseContainer")))
@interface MDTMHttpResponseContainer : MDTMBase
- (instancetype)initWithExpectedType:(MDTMKtor_utilsTypeInfo *)expectedType response:(id)response __attribute__((swift_name("init(expectedType:response:)"))) __attribute__((objc_designated_initializer));
- (MDTMHttpResponseContainer *)doCopyExpectedType:(MDTMKtor_utilsTypeInfo *)expectedType response:(id)response __attribute__((swift_name("doCopy(expectedType:response:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) MDTMKtor_utilsTypeInfo *expectedType __attribute__((swift_name("expectedType")));
@property (readonly) id response __attribute__((swift_name("response")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpResponsePipeline")))
@interface MDTMHttpResponsePipeline : MDTMKtor_utilsPipeline<MDTMHttpResponseContainer *, MDTMHttpClientCall *>
- (instancetype)initWithDevelopmentMode:(BOOL)developmentMode __attribute__((swift_name("init(developmentMode:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithPhases:(MDTMKotlinArray<MDTMKtor_utilsPipelinePhase *> *)phases __attribute__((swift_name("init(phases:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithPhase:(MDTMKtor_utilsPipelinePhase *)phase interceptors:(NSArray<id<MDTMKotlinSuspendFunction2>> *)interceptors __attribute__((swift_name("init(phase:interceptors:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) MDTMHttpResponsePipelinePhases *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL developmentMode __attribute__((swift_name("developmentMode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpResponsePipeline.Phases")))
@interface MDTMHttpResponsePipelinePhases : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)phases __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMHttpResponsePipelinePhases *shared __attribute__((swift_name("shared")));
@property (readonly) MDTMKtor_utilsPipelinePhase *After __attribute__((swift_name("After")));
@property (readonly) MDTMKtor_utilsPipelinePhase *Parse __attribute__((swift_name("Parse")));
@property (readonly) MDTMKtor_utilsPipelinePhase *Receive __attribute__((swift_name("Receive")));
@property (readonly) MDTMKtor_utilsPipelinePhase *State __attribute__((swift_name("State")));
@property (readonly) MDTMKtor_utilsPipelinePhase *Transform __attribute__((swift_name("Transform")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpStatement")))
@interface MDTMHttpStatement : MDTMBase
- (instancetype)initWithBuilder:(MDTMHttpRequestBuilder *)builder client:(MDTMHttpClient *)client __attribute__((swift_name("init(builder:client:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyWithCompletionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("body(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyBlock:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("body(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)executeWithCompletionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("execute(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)executeBlock:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("execute(block:completionHandler:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CacheControl")))
@interface MDTMCacheControl : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cacheControl __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMCacheControl *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *MAX_AGE __attribute__((swift_name("MAX_AGE")));
@property (readonly) NSString *MAX_STALE __attribute__((swift_name("MAX_STALE")));
@property (readonly) NSString *MIN_FRESH __attribute__((swift_name("MIN_FRESH")));
@property (readonly) NSString *MUST_REVALIDATE __attribute__((swift_name("MUST_REVALIDATE")));
@property (readonly) NSString *NO_CACHE __attribute__((swift_name("NO_CACHE")));
@property (readonly) NSString *NO_STORE __attribute__((swift_name("NO_STORE")));
@property (readonly) NSString *NO_TRANSFORM __attribute__((swift_name("NO_TRANSFORM")));
@property (readonly) NSString *ONLY_IF_CACHED __attribute__((swift_name("ONLY_IF_CACHED")));
@property (readonly) NSString *PRIVATE __attribute__((swift_name("PRIVATE")));
@property (readonly) NSString *PROXY_REVALIDATE __attribute__((swift_name("PROXY_REVALIDATE")));
@property (readonly) NSString *PUBLIC __attribute__((swift_name("PUBLIC")));
@property (readonly) NSString *S_MAX_AGE __attribute__((swift_name("S_MAX_AGE")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EmptyContent")))
@interface MDTMEmptyContent : MDTMKtor_httpOutgoingContentNoContent
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)emptyContent __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMEmptyContent *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) MDTMLong *contentLength __attribute__((swift_name("contentLength")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpResponseReceiveFail")))
@interface MDTMHttpResponseReceiveFail : MDTMBase
- (instancetype)initWithResponse:(MDTMHttpResponse *)response cause:(MDTMKotlinThrowable *)cause __attribute__((swift_name("init(response:cause:)"))) __attribute__((objc_designated_initializer));
@property (readonly) MDTMKotlinThrowable *cause __attribute__((swift_name("cause")));
@property (readonly) MDTMHttpResponse *response __attribute__((swift_name("response")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinCoroutineContext")))
@protocol MDTMKotlinCoroutineContext
@required
- (id _Nullable)foldInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<MDTMKotlinCoroutineContextElement>))operation __attribute__((swift_name("fold(initial:operation:)")));
- (id<MDTMKotlinCoroutineContextElement> _Nullable)getKey:(id<MDTMKotlinCoroutineContextKey>)key __attribute__((swift_name("get(key:)")));
- (id<MDTMKotlinCoroutineContext>)minusKeyKey:(id<MDTMKotlinCoroutineContextKey>)key __attribute__((swift_name("minusKey(key:)")));
- (id<MDTMKotlinCoroutineContext>)plusContext:(id<MDTMKotlinCoroutineContext>)context __attribute__((swift_name("plus(context:)")));
@end

__attribute__((swift_name("KotlinCoroutineContextElement")))
@protocol MDTMKotlinCoroutineContextElement <MDTMKotlinCoroutineContext>
@required
@property (readonly) id<MDTMKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end

__attribute__((swift_name("Job")))
@protocol MDTMJob <MDTMKotlinCoroutineContextElement>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id<MDTMChildHandle>)attachChildChild:(id<MDTMChildJob>)child __attribute__((swift_name("attachChild(child:)")));
- (void)cancelCause:(MDTMKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancel(cause:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (MDTMKotlinCancellationException *)getCancellationException __attribute__((swift_name("getCancellationException()")));
- (id<MDTMDisposableHandle>)invokeOnCompletionHandler:(void (^)(MDTMKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(handler:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id<MDTMDisposableHandle>)invokeOnCompletionOnCancelling:(BOOL)onCancelling invokeImmediately:(BOOL)invokeImmediately handler:(void (^)(MDTMKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(onCancelling:invokeImmediately:handler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)joinWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("join(completionHandler:)")));
- (id<MDTMJob>)plusOther:(id<MDTMJob>)other __attribute__((swift_name("plus(other:)"))) __attribute__((unavailable("Operator '+' on two Job objects is meaningless. Job is a coroutine context element and `+` is a set-sum operator for coroutine contexts. The job to the right of `+` just replaces the job the left of `+`.")));
- (BOOL)start __attribute__((swift_name("start()")));
@property (readonly) id<MDTMKotlinSequence> children __attribute__((swift_name("children")));
@property (readonly) BOOL isActive __attribute__((swift_name("isActive")));
@property (readonly) BOOL isCancelled __attribute__((swift_name("isCancelled")));
@property (readonly) BOOL isCompleted __attribute__((swift_name("isCompleted")));
@property (readonly) id<MDTMSelectClause0> onJoin __attribute__((swift_name("onJoin")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
@property (readonly) id<MDTMJob> _Nullable parent __attribute__((swift_name("parent")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("ChildJob")))
@protocol MDTMChildJob <MDTMJob>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (void)parentCancelledParentJob:(id<MDTMParentJob>)parentJob __attribute__((swift_name("parentCancelled(parentJob:)")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("ParentJob")))
@protocol MDTMParentJob <MDTMJob>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (MDTMKotlinCancellationException *)getChildJobCancellationCause __attribute__((swift_name("getChildJobCancellationCause()")));
@end

__attribute__((swift_name("JobSupport")))
@interface MDTMJobSupport : MDTMBase <MDTMJob, MDTMChildJob, MDTMParentJob>
- (instancetype)initWithActive:(BOOL)active __attribute__((swift_name("init(active:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable("This is internal API and may be removed in the future releases")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)afterCompletionState:(id _Nullable)state __attribute__((swift_name("afterCompletion(state:)")));
- (id<MDTMChildHandle>)attachChildChild:(id<MDTMChildJob>)child __attribute__((swift_name("attachChild(child:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)awaitInternalWithCompletionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("awaitInternal(completionHandler:)")));
- (void)cancelCause:(MDTMKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancel(cause:)")));
- (BOOL)cancelCoroutineCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("cancelCoroutine(cause:)")));
- (void)cancelInternalCause:(MDTMKotlinThrowable *)cause __attribute__((swift_name("cancelInternal(cause:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString *)cancellationExceptionMessage __attribute__((swift_name("cancellationExceptionMessage()")));
- (BOOL)childCancelledCause:(MDTMKotlinThrowable *)cause __attribute__((swift_name("childCancelled(cause:)")));
- (MDTMKotlinCancellationException *)getCancellationException __attribute__((swift_name("getCancellationException()")));
- (MDTMKotlinCancellationException *)getChildJobCancellationCause __attribute__((swift_name("getChildJobCancellationCause()")));
- (MDTMKotlinThrowable * _Nullable)getCompletionExceptionOrNull __attribute__((swift_name("getCompletionExceptionOrNull()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (BOOL)handleJobExceptionException:(MDTMKotlinThrowable *)exception __attribute__((swift_name("handleJobException(exception:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)doInitParentJobParent:(id<MDTMJob> _Nullable)parent __attribute__((swift_name("doInitParentJob(parent:)")));
- (id<MDTMDisposableHandle>)invokeOnCompletionHandler:(void (^)(MDTMKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(handler:)")));
- (id<MDTMDisposableHandle>)invokeOnCompletionOnCancelling:(BOOL)onCancelling invokeImmediately:(BOOL)invokeImmediately handler:(void (^)(MDTMKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(onCancelling:invokeImmediately:handler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)joinWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("join(completionHandler:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)onCancellingCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("onCancelling(cause:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)onCompletionInternalState:(id _Nullable)state __attribute__((swift_name("onCompletionInternal(state:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)onStart __attribute__((swift_name("onStart()")));
- (void)parentCancelledParentJob:(id<MDTMParentJob>)parentJob __attribute__((swift_name("parentCancelled(parentJob:)")));
- (BOOL)start __attribute__((swift_name("start()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (MDTMKotlinCancellationException *)toCancellationException:(MDTMKotlinThrowable *)receiver message:(NSString * _Nullable)message __attribute__((swift_name("toCancellationException(_:message:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (NSString *)toDebugString __attribute__((swift_name("toDebugString()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<MDTMKotlinSequence> children __attribute__((swift_name("children")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) MDTMKotlinThrowable * _Nullable completionCause __attribute__((swift_name("completionCause")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) BOOL completionCauseHandled __attribute__((swift_name("completionCauseHandled")));
@property (readonly) BOOL isActive __attribute__((swift_name("isActive")));
@property (readonly) BOOL isCancelled __attribute__((swift_name("isCancelled")));
@property (readonly) BOOL isCompleted __attribute__((swift_name("isCompleted")));
@property (readonly) BOOL isCompletedExceptionally __attribute__((swift_name("isCompletedExceptionally")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) BOOL isScopedCoroutine __attribute__((swift_name("isScopedCoroutine")));
@property (readonly) id<MDTMKotlinCoroutineContextKey> key __attribute__((swift_name("key")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) id<MDTMSelectClause1> onAwaitInternal __attribute__((swift_name("onAwaitInternal")));
@property (readonly) id<MDTMSelectClause0> onJoin __attribute__((swift_name("onJoin")));
@property (readonly) id<MDTMJob> _Nullable parent __attribute__((swift_name("parent")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuation")))
@protocol MDTMKotlinContinuation
@required
- (void)resumeWithResult:(id _Nullable)result __attribute__((swift_name("resumeWith(result:)")));
@property (readonly) id<MDTMKotlinCoroutineContext> context __attribute__((swift_name("context")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("AbstractCoroutine")))
@interface MDTMAbstractCoroutine<__contravariant T> : MDTMJobSupport <MDTMJob, MDTMKotlinContinuation, MDTMCoroutineScope>
- (instancetype)initWithParentContext:(id<MDTMKotlinCoroutineContext>)parentContext initParentJob:(BOOL)initParentJob active:(BOOL)active __attribute__((swift_name("init(parentContext:initParentJob:active:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithActive:(BOOL)active __attribute__((swift_name("init(active:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)afterResumeState:(id _Nullable)state __attribute__((swift_name("afterResume(state:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString *)cancellationExceptionMessage __attribute__((swift_name("cancellationExceptionMessage()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)onCancelledCause:(MDTMKotlinThrowable *)cause handled:(BOOL)handled __attribute__((swift_name("onCancelled(cause:handled:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)onCompletedValue:(T _Nullable)value __attribute__((swift_name("onCompleted(value:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)onCompletionInternalState:(id _Nullable)state __attribute__((swift_name("onCompletionInternal(state:)")));
- (void)resumeWithResult:(id _Nullable)result __attribute__((swift_name("resumeWith(result:)")));
- (void)startStart:(MDTMCoroutineStart *)start receiver:(id _Nullable)receiver block:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("start(start:receiver:block:)")));
@property (readonly) id<MDTMKotlinCoroutineContext> context __attribute__((swift_name("context")));
@property (readonly) id<MDTMKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@property (readonly) BOOL isActive __attribute__((swift_name("isActive")));
@end

__attribute__((swift_name("CancellableContinuation")))
@protocol MDTMCancellableContinuation <MDTMKotlinContinuation>
@required
- (BOOL)cancelCause_:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("cancel(cause_:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (void)completeResumeToken:(id)token __attribute__((swift_name("completeResume(token:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (void)doInitCancellability __attribute__((swift_name("doInitCancellability()")));
- (void)invokeOnCancellationHandler:(void (^)(MDTMKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCancellation(handler:)")));
- (void)resumeValue:(id _Nullable)value onCancellation:(void (^ _Nullable)(MDTMKotlinThrowable *, id _Nullable, id<MDTMKotlinCoroutineContext>))onCancellation __attribute__((swift_name("resume(value:onCancellation:)")));
- (void)resumeValue:(id _Nullable)value onCancellation_:(void (^ _Nullable)(MDTMKotlinThrowable *))onCancellation __attribute__((swift_name("resume(value:onCancellation_:)"))) __attribute__((deprecated("Use the overload that also accepts the `value` and the coroutine context in lambda")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (void)resumeUndispatched:(MDTMCoroutineDispatcher *)receiver value:(id _Nullable)value __attribute__((swift_name("resumeUndispatched(_:value:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (void)resumeUndispatchedWithException:(MDTMCoroutineDispatcher *)receiver exception:(MDTMKotlinThrowable *)exception __attribute__((swift_name("resumeUndispatchedWithException(_:exception:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id _Nullable)tryResumeValue:(id _Nullable)value idempotent:(id _Nullable)idempotent __attribute__((swift_name("tryResume(value:idempotent:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id _Nullable)tryResumeValue:(id _Nullable)value idempotent:(id _Nullable)idempotent onCancellation:(void (^ _Nullable)(MDTMKotlinThrowable *, id _Nullable, id<MDTMKotlinCoroutineContext>))onCancellation __attribute__((swift_name("tryResume(value:idempotent:onCancellation:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (id _Nullable)tryResumeWithExceptionException:(MDTMKotlinThrowable *)exception __attribute__((swift_name("tryResumeWithException(exception:)")));
@property (readonly) BOOL isActive __attribute__((swift_name("isActive")));
@property (readonly) BOOL isCancelled __attribute__((swift_name("isCancelled")));
@property (readonly) BOOL isCompleted __attribute__((swift_name("isCompleted")));
@end

__attribute__((swift_name("DisposableHandle")))
@protocol MDTMDisposableHandle
@required
- (void)dispose __attribute__((swift_name("dispose()")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("ChildHandle")))
@protocol MDTMChildHandle <MDTMDisposableHandle>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (BOOL)childCancelledCause:(MDTMKotlinThrowable *)cause __attribute__((swift_name("childCancelled(cause:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
@property (readonly) id<MDTMJob> _Nullable parent __attribute__((swift_name("parent")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextElement")))
@interface MDTMKotlinAbstractCoroutineContextElement : MDTMBase <MDTMKotlinCoroutineContextElement>
- (instancetype)initWithKey:(id<MDTMKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id<MDTMKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinContinuationInterceptor")))
@protocol MDTMKotlinContinuationInterceptor <MDTMKotlinCoroutineContextElement>
@required
- (id<MDTMKotlinContinuation>)interceptContinuationContinuation:(id<MDTMKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (void)releaseInterceptedContinuationContinuation:(id<MDTMKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
@end

__attribute__((swift_name("CoroutineDispatcher")))
@interface MDTMCoroutineDispatcher : MDTMKotlinAbstractCoroutineContextElement <MDTMKotlinContinuationInterceptor>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithKey:(id<MDTMKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) MDTMCoroutineDispatcherKey *companion __attribute__((swift_name("companion")));
- (void)dispatchContext:(id<MDTMKotlinCoroutineContext>)context block:(id<MDTMRunnable>)block __attribute__((swift_name("dispatch(context:block:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (void)dispatchYieldContext:(id<MDTMKotlinCoroutineContext>)context block:(id<MDTMRunnable>)block __attribute__((swift_name("dispatchYield(context:block:)")));
- (id<MDTMKotlinContinuation>)interceptContinuationContinuation:(id<MDTMKotlinContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
- (BOOL)isDispatchNeededContext:(id<MDTMKotlinCoroutineContext>)context __attribute__((swift_name("isDispatchNeeded(context:)")));
- (MDTMCoroutineDispatcher *)limitedParallelismParallelism:(int32_t)parallelism name:(NSString * _Nullable)name __attribute__((swift_name("limitedParallelism(parallelism:name:)")));
- (MDTMCoroutineDispatcher *)plusOther_:(MDTMCoroutineDispatcher *)other __attribute__((swift_name("plus(other_:)"))) __attribute__((unavailable("Operator '+' on two CoroutineDispatcher objects is meaningless. CoroutineDispatcher is a coroutine context element and `+` is a set-sum operator for coroutine contexts. The dispatcher to the right of `+` just replaces the dispatcher to the left.")));
- (void)releaseInterceptedContinuationContinuation:(id<MDTMKotlinContinuation>)continuation __attribute__((swift_name("releaseInterceptedContinuation(continuation:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("CloseableCoroutineDispatcher")))
@interface MDTMCloseableCoroutineDispatcher : MDTMCoroutineDispatcher <MDTMKotlinAutoCloseable>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)close __attribute__((swift_name("close()")));
@end

__attribute__((swift_name("Deferred")))
@protocol MDTMDeferred <MDTMJob>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)awaitWithCompletionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("await(completionHandler:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (id _Nullable)getCompleted __attribute__((swift_name("getCompleted()")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (MDTMKotlinThrowable * _Nullable)getCompletionExceptionOrNull __attribute__((swift_name("getCompletionExceptionOrNull()")));
@property (readonly) id<MDTMSelectClause1> onAwait __attribute__((swift_name("onAwait")));
@end

__attribute__((swift_name("CompletableDeferred")))
@protocol MDTMCompletableDeferred <MDTMDeferred>
@required
- (BOOL)completeValue:(id _Nullable)value __attribute__((swift_name("complete(value:)")));
- (BOOL)completeExceptionallyException:(MDTMKotlinThrowable *)exception __attribute__((swift_name("completeExceptionally(exception:)")));
@end

__attribute__((swift_name("CompletableJob")))
@protocol MDTMCompletableJob <MDTMJob>
@required
- (BOOL)complete __attribute__((swift_name("complete()")));
- (BOOL)completeExceptionallyException:(MDTMKotlinThrowable *)exception __attribute__((swift_name("completeExceptionally(exception:)")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CompletionHandlerException")))
@interface MDTMCompletionHandlerException : MDTMKotlinRuntimeException
- (instancetype)initWithMessage:(NSString *)message cause:(MDTMKotlinThrowable *)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinCoroutineContextKey")))
@protocol MDTMKotlinCoroutineContextKey
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((swift_name("KotlinAbstractCoroutineContextKey")))
@interface MDTMKotlinAbstractCoroutineContextKey<B, E> : MDTMBase <MDTMKotlinCoroutineContextKey>
- (instancetype)initWithBaseKey:(id<MDTMKotlinCoroutineContextKey>)baseKey safeCast:(E _Nullable (^)(id<MDTMKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.ExperimentalStdlibApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoroutineDispatcher.Key")))
@interface MDTMCoroutineDispatcherKey : MDTMKotlinAbstractCoroutineContextKey<id<MDTMKotlinContinuationInterceptor>, MDTMCoroutineDispatcher *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithBaseKey:(id<MDTMKotlinCoroutineContextKey>)baseKey safeCast:(id<MDTMKotlinCoroutineContextElement> _Nullable (^)(id<MDTMKotlinCoroutineContextElement>))safeCast __attribute__((swift_name("init(baseKey:safeCast:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)key __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMCoroutineDispatcherKey *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("CoroutineExceptionHandler")))
@protocol MDTMCoroutineExceptionHandler <MDTMKotlinCoroutineContextElement>
@required
- (void)handleExceptionContext:(id<MDTMKotlinCoroutineContext>)context exception:(MDTMKotlinThrowable *)exception __attribute__((swift_name("handleException(context:exception:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoroutineExceptionHandlerKey")))
@interface MDTMCoroutineExceptionHandlerKey : MDTMBase <MDTMKotlinCoroutineContextKey>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)key __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMCoroutineExceptionHandlerKey *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoroutineName")))
@interface MDTMCoroutineName : MDTMKotlinAbstractCoroutineContextElement
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithKey:(id<MDTMKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) MDTMCoroutineNameKey *companion __attribute__((swift_name("companion")));
- (MDTMCoroutineName *)doCopyName:(NSString *)name __attribute__((swift_name("doCopy(name:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoroutineName.Key")))
@interface MDTMCoroutineNameKey : MDTMBase <MDTMKotlinCoroutineContextKey>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)key __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMCoroutineNameKey *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoroutineStart")))
@interface MDTMCoroutineStart : MDTMKotlinEnum<MDTMCoroutineStart *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) MDTMCoroutineStart *default_ __attribute__((swift_name("default_")));
@property (class, readonly) MDTMCoroutineStart *lazy __attribute__((swift_name("lazy")));
@property (class, readonly) MDTMCoroutineStart *atomic __attribute__((swift_name("atomic")));
@property (class, readonly) MDTMCoroutineStart *undispatched __attribute__((swift_name("undispatched")));
+ (MDTMKotlinArray<MDTMCoroutineStart *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<MDTMCoroutineStart *> *entries __attribute__((swift_name("entries")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
- (void)invokeBlock:(id<MDTMKotlinSuspendFunction1>)block receiver:(id _Nullable)receiver completion:(id<MDTMKotlinContinuation>)completion __attribute__((swift_name("invoke(block:receiver:completion:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
@property (readonly) BOOL isLazy __attribute__((swift_name("isLazy")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("Delay")))
@protocol MDTMDelay
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)delayTime:(int64_t)time completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("delay(time:completionHandler:)"))) __attribute__((unavailable("Deprecated without replacement as an internal method never intended for public use")));
- (id<MDTMDisposableHandle>)invokeOnTimeoutTimeMillis:(int64_t)timeMillis block:(id<MDTMRunnable>)block context:(id<MDTMKotlinCoroutineContext>)context __attribute__((swift_name("invokeOnTimeout(timeMillis:block:context:)")));
- (void)scheduleResumeAfterDelayTimeMillis:(int64_t)timeMillis continuation:(id<MDTMCancellableContinuation>)continuation __attribute__((swift_name("scheduleResumeAfterDelay(timeMillis:continuation:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Dispatchers")))
@interface MDTMDispatchers : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dispatchers __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMDispatchers *shared __attribute__((swift_name("shared")));
@property (readonly) MDTMCoroutineDispatcher *Default __attribute__((swift_name("Default")));
@property (readonly) MDTMMainCoroutineDispatcher *Main __attribute__((swift_name("Main")));
@property (readonly) MDTMCoroutineDispatcher *Unconfined __attribute__((swift_name("Unconfined")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.DelicateCoroutinesApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GlobalScope")))
@interface MDTMGlobalScope : MDTMBase <MDTMCoroutineScope>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)globalScope __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMGlobalScope *shared __attribute__((swift_name("shared")));
@property (readonly) id<MDTMKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("JobKey")))
@interface MDTMJobKey : MDTMBase <MDTMKotlinCoroutineContextKey>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)key __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMJobKey *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("MainCoroutineDispatcher")))
@interface MDTMMainCoroutineDispatcher : MDTMCoroutineDispatcher
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (MDTMCoroutineDispatcher *)limitedParallelismParallelism:(int32_t)parallelism name:(NSString * _Nullable)name __attribute__((swift_name("limitedParallelism(parallelism:name:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString * _Nullable)toStringInternalImpl __attribute__((swift_name("toStringInternalImpl()")));
@property (readonly) MDTMMainCoroutineDispatcher *immediate __attribute__((swift_name("immediate")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NonCancellable")))
@interface MDTMNonCancellable : MDTMKotlinAbstractCoroutineContextElement <MDTMJob>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithKey:(id<MDTMKotlinCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)nonCancellable __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMNonCancellable *shared __attribute__((swift_name("shared")));
- (id<MDTMChildHandle>)attachChildChild:(id<MDTMChildJob>)child __attribute__((swift_name("attachChild(child:)"))) __attribute__((deprecated("NonCancellable can be used only as an argument for 'withContext', direct usages of its API are prohibited")));
- (void)cancelCause:(MDTMKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancel(cause:)"))) __attribute__((deprecated("NonCancellable can be used only as an argument for 'withContext', direct usages of its API are prohibited")));
- (MDTMKotlinCancellationException *)getCancellationException __attribute__((swift_name("getCancellationException()"))) __attribute__((deprecated("NonCancellable can be used only as an argument for 'withContext', direct usages of its API are prohibited")));
- (id<MDTMDisposableHandle>)invokeOnCompletionHandler:(void (^)(MDTMKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(handler:)"))) __attribute__((deprecated("NonCancellable can be used only as an argument for 'withContext', direct usages of its API are prohibited")));
- (id<MDTMDisposableHandle>)invokeOnCompletionOnCancelling:(BOOL)onCancelling invokeImmediately:(BOOL)invokeImmediately handler:(void (^)(MDTMKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnCompletion(onCancelling:invokeImmediately:handler:)"))) __attribute__((deprecated("NonCancellable can be used only as an argument for 'withContext', direct usages of its API are prohibited")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)joinWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("join(completionHandler:)"))) __attribute__((deprecated("NonCancellable can be used only as an argument for 'withContext', direct usages of its API are prohibited")));
- (BOOL)start __attribute__((swift_name("start()"))) __attribute__((deprecated("NonCancellable can be used only as an argument for 'withContext', direct usages of its API are prohibited")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<MDTMKotlinSequence> children __attribute__((swift_name("children"))) __attribute__((deprecated("NonCancellable can be used only as an argument for 'withContext', direct usages of its API are prohibited")));
@property (readonly) BOOL isActive __attribute__((swift_name("isActive"))) __attribute__((deprecated("NonCancellable can be used only as an argument for 'withContext', direct usages of its API are prohibited")));
@property (readonly) BOOL isCancelled __attribute__((swift_name("isCancelled"))) __attribute__((deprecated("NonCancellable can be used only as an argument for 'withContext', direct usages of its API are prohibited")));
@property (readonly) BOOL isCompleted __attribute__((swift_name("isCompleted"))) __attribute__((deprecated("NonCancellable can be used only as an argument for 'withContext', direct usages of its API are prohibited")));
@property (readonly) id<MDTMSelectClause0> onJoin __attribute__((swift_name("onJoin"))) __attribute__((deprecated("NonCancellable can be used only as an argument for 'withContext', direct usages of its API are prohibited")));
@property (readonly) id<MDTMJob> _Nullable parent __attribute__((swift_name("parent"))) __attribute__((deprecated("NonCancellable can be used only as an argument for 'withContext', direct usages of its API are prohibited")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NonDisposableHandle")))
@interface MDTMNonDisposableHandle : MDTMBase <MDTMDisposableHandle, MDTMChildHandle>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)nonDisposableHandle __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMNonDisposableHandle *shared __attribute__((swift_name("shared")));
- (BOOL)childCancelledCause:(MDTMKotlinThrowable *)cause __attribute__((swift_name("childCancelled(cause:)")));
- (void)dispose __attribute__((swift_name("dispose()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<MDTMJob> _Nullable parent __attribute__((swift_name("parent")));
@end

__attribute__((swift_name("Runnable")))
@protocol MDTMRunnable
@required
- (void)run __attribute__((swift_name("run()")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface MDTMKotlinCancellationException : MDTMKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimeoutCancellationException")))
@interface MDTMTimeoutCancellationException : MDTMKotlinCancellationException <MDTMCopyableThrowable>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (MDTMTimeoutCancellationException *)createCopy __attribute__((swift_name("createCopy()")));
@end

__attribute__((swift_name("SendChannel")))
@protocol MDTMSendChannel
@required
- (BOOL)closeCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("close(cause:)")));
- (void)invokeOnCloseHandler:(void (^)(MDTMKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnClose(handler:)")));
- (BOOL)offerElement:(id _Nullable)element __attribute__((swift_name("offer(element:)"))) __attribute__((unavailable("Deprecated in the favour of 'trySend' method")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sendElement:(id _Nullable)element completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("send(element:completionHandler:)")));
- (id _Nullable)trySendElement:(id _Nullable)element __attribute__((swift_name("trySend(element:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.DelicateCoroutinesApi
*/
@property (readonly) BOOL isClosedForSend __attribute__((swift_name("isClosedForSend")));
@property (readonly) id<MDTMSelectClause2> onSend __attribute__((swift_name("onSend")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.ObsoleteCoroutinesApi
*/
__attribute__((swift_name("BroadcastChannel")))
@protocol MDTMBroadcastChannel <MDTMSendChannel>
@required
- (void)cancelCause:(MDTMKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancel(cause:)")));
- (id<MDTMReceiveChannel>)openSubscription __attribute__((swift_name("openSubscription()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BufferOverflow")))
@interface MDTMBufferOverflow : MDTMKotlinEnum<MDTMBufferOverflow *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) MDTMBufferOverflow *suspend __attribute__((swift_name("suspend")));
@property (class, readonly) MDTMBufferOverflow *dropOldest __attribute__((swift_name("dropOldest")));
@property (class, readonly) MDTMBufferOverflow *dropLatest __attribute__((swift_name("dropLatest")));
+ (MDTMKotlinArray<MDTMBufferOverflow *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<MDTMBufferOverflow *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((swift_name("ReceiveChannel")))
@protocol MDTMReceiveChannel
@required
- (void)cancelCause:(MDTMKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancel(cause:)")));
- (id<MDTMChannelIterator>)iterator __attribute__((swift_name("iterator()")));
- (id _Nullable)poll __attribute__((swift_name("poll()"))) __attribute__((unavailable("Deprecated in the favour of 'tryReceive'. Please note that the provided replacement does not rethrow channel's close cause as 'poll' did, for the precise replacement please refer to the 'poll' documentation")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)receiveWithCompletionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("receive(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)receiveCatchingWithCompletionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("receiveCatching(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)receiveOrNullWithCompletionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("receiveOrNull(completionHandler:)"))) __attribute__((unavailable("Deprecated in favor of 'receiveCatching'. Please note that the provided replacement does not rethrow channel's close cause as 'receiveOrNull' did, for the detailed replacement please refer to the 'receiveOrNull' documentation")));
- (id _Nullable)tryReceive __attribute__((swift_name("tryReceive()")));

/**
 * @note annotations
 *   kotlinx.coroutines.DelicateCoroutinesApi
*/
@property (readonly) BOOL isClosedForReceive __attribute__((swift_name("isClosedForReceive")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
@property (readonly) BOOL isEmpty __attribute__((swift_name("isEmpty")));
@property (readonly) id<MDTMSelectClause1> onReceive __attribute__((swift_name("onReceive")));
@property (readonly) id<MDTMSelectClause1> onReceiveCatching __attribute__((swift_name("onReceiveCatching")));
@property (readonly) id<MDTMSelectClause1> onReceiveOrNull __attribute__((swift_name("onReceiveOrNull"))) __attribute__((unavailable("Deprecated in favor of onReceiveCatching extension")));
@end

__attribute__((swift_name("Channel")))
@protocol MDTMChannel <MDTMSendChannel, MDTMReceiveChannel>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChannelFactory")))
@interface MDTMChannelFactory : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)factory __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMChannelFactory *shared __attribute__((swift_name("shared")));
@property (readonly) int32_t BUFFERED __attribute__((swift_name("BUFFERED")));
@property (readonly) int32_t CONFLATED __attribute__((swift_name("CONFLATED")));

/**
 * @note annotations
 *   kotlinx.coroutines.DelicateCoroutinesApi
*/
@property (readonly) NSString *DEFAULT_BUFFER_PROPERTY_NAME __attribute__((swift_name("DEFAULT_BUFFER_PROPERTY_NAME")));
@property (readonly) int32_t RENDEZVOUS __attribute__((swift_name("RENDEZVOUS")));
@property (readonly) int32_t UNLIMITED __attribute__((swift_name("UNLIMITED")));
@end

__attribute__((swift_name("ChannelIterator")))
@protocol MDTMChannelIterator
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)hasNextWithCompletionHandler:(void (^)(MDTMBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("hasNext(completionHandler:)")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((swift_name("KotlinNoSuchElementException")))
@interface MDTMKotlinNoSuchElementException : MDTMKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ClosedReceiveChannelException")))
@interface MDTMClosedReceiveChannelException : MDTMKotlinNoSuchElementException
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ClosedSendChannelException")))
@interface MDTMClosedSendChannelException : MDTMKotlinIllegalStateException
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.ObsoleteCoroutinesApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConflatedBroadcastChannel")))
@interface MDTMConflatedBroadcastChannel<E> : MDTMBase <MDTMBroadcastChannel>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable("ConflatedBroadcastChannel is deprecated in the favour of SharedFlow and is no longer supported")));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithValue:(E _Nullable)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable("ConflatedBroadcastChannel is deprecated in the favour of SharedFlow and is no longer supported")));
- (void)cancelCause:(MDTMKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancel(cause:)")));
- (BOOL)closeCause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("close(cause:)")));
- (void)invokeOnCloseHandler:(void (^)(MDTMKotlinThrowable * _Nullable))handler __attribute__((swift_name("invokeOnClose(handler:)")));
- (BOOL)offerElement:(E _Nullable)element __attribute__((swift_name("offer(element:)"))) __attribute__((unavailable("Deprecated in the favour of 'trySend' method")));
- (id<MDTMReceiveChannel>)openSubscription __attribute__((swift_name("openSubscription()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sendElement:(E _Nullable)element completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("send(element:completionHandler:)")));
- (id _Nullable)trySendElement:(E _Nullable)element __attribute__((swift_name("trySend(element:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.DelicateCoroutinesApi
*/
@property (readonly) BOOL isClosedForSend __attribute__((swift_name("isClosedForSend")));
@property (readonly) id<MDTMSelectClause2> onSend __attribute__((swift_name("onSend")));
@property (readonly) E _Nullable value __attribute__((swift_name("value")));
@property (readonly) E _Nullable valueOrNull __attribute__((swift_name("valueOrNull")));
@end

__attribute__((swift_name("ProducerScope")))
@protocol MDTMProducerScope <MDTMCoroutineScope, MDTMSendChannel>
@required
@property (readonly) id<MDTMSendChannel> channel __attribute__((swift_name("channel")));
@end

__attribute__((swift_name("Flow")))
@protocol MDTMFlow
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<MDTMFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
__attribute__((swift_name("AbstractFlow")))
@interface MDTMAbstractFlow<T> : MDTMBase <MDTMFlow>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<MDTMFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectSafelyCollector:(id<MDTMFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collectSafely(collector:completionHandler:)")));
@end

__attribute__((swift_name("FlowCollector")))
@protocol MDTMFlowCollector
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)emitValue:(id _Nullable)value completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emit(value:completionHandler:)")));
@end

__attribute__((swift_name("SharedFlow")))
@protocol MDTMSharedFlow <MDTMFlow>
@required
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
@end

__attribute__((swift_name("MutableSharedFlow")))
@protocol MDTMMutableSharedFlow <MDTMSharedFlow, MDTMFlowCollector>
@required

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (void)resetReplayCache __attribute__((swift_name("resetReplayCache()")));
- (BOOL)tryEmitValue:(id _Nullable)value __attribute__((swift_name("tryEmit(value:)")));
@property (readonly) id<MDTMStateFlow> subscriptionCount __attribute__((swift_name("subscriptionCount")));
@end

__attribute__((swift_name("StateFlow")))
@protocol MDTMStateFlow <MDTMSharedFlow>
@required
@property (readonly) id _Nullable value __attribute__((swift_name("value")));
@end

__attribute__((swift_name("MutableStateFlow")))
@protocol MDTMMutableStateFlow <MDTMStateFlow, MDTMMutableSharedFlow>
@required
- (void)setValue:(id _Nullable)value __attribute__((swift_name("setValue(_:)")));
- (BOOL)compareAndSetExpect:(id _Nullable)expect update:(id _Nullable)update __attribute__((swift_name("compareAndSet(expect:update:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SharingCommand")))
@interface MDTMSharingCommand : MDTMKotlinEnum<MDTMSharingCommand *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) MDTMSharingCommand *start __attribute__((swift_name("start")));
@property (class, readonly) MDTMSharingCommand *stop __attribute__((swift_name("stop")));
@property (class, readonly) MDTMSharingCommand *stopAndResetReplayCache __attribute__((swift_name("stopAndResetReplayCache")));
+ (MDTMKotlinArray<MDTMSharingCommand *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<MDTMSharingCommand *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((swift_name("SharingStarted")))
@protocol MDTMSharingStarted
@required
- (id<MDTMFlow>)commandSubscriptionCount:(id<MDTMStateFlow>)subscriptionCount __attribute__((swift_name("command(subscriptionCount:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SharingStartedCompanion")))
@interface MDTMSharingStartedCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMSharingStartedCompanion *shared __attribute__((swift_name("shared")));
- (id<MDTMSharingStarted>)WhileSubscribedStopTimeoutMillis:(int64_t)stopTimeoutMillis replayExpirationMillis:(int64_t)replayExpirationMillis __attribute__((swift_name("WhileSubscribed(stopTimeoutMillis:replayExpirationMillis:)")));
@property (readonly) id<MDTMSharingStarted> Eagerly __attribute__((swift_name("Eagerly")));
@property (readonly) id<MDTMSharingStarted> Lazily __attribute__((swift_name("Lazily")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("FusibleFlow")))
@protocol MDTMFusibleFlow <MDTMFlow>
@required
- (id<MDTMFlow>)fuseContext:(id<MDTMKotlinCoroutineContext>)context capacity:(int32_t)capacity onBufferOverflow:(MDTMBufferOverflow *)onBufferOverflow __attribute__((swift_name("fuse(context:capacity:onBufferOverflow:)")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("ChannelFlow")))
@interface MDTMChannelFlow<T> : MDTMBase <MDTMFusibleFlow>
- (instancetype)initWithContext:(id<MDTMKotlinCoroutineContext>)context capacity:(int32_t)capacity onBufferOverflow:(MDTMBufferOverflow *)onBufferOverflow __attribute__((swift_name("init(context:capacity:onBufferOverflow:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString * _Nullable)additionalToStringProps __attribute__((swift_name("additionalToStringProps()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<MDTMFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)collectToScope:(id<MDTMProducerScope>)scope completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collectTo(scope:completionHandler:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (MDTMChannelFlow<T> *)createContext:(id<MDTMKotlinCoroutineContext>)context capacity:(int32_t)capacity onBufferOverflow:(MDTMBufferOverflow *)onBufferOverflow __attribute__((swift_name("create(context:capacity:onBufferOverflow:)")));
- (id<MDTMFlow> _Nullable)dropChannelOperators __attribute__((swift_name("dropChannelOperators()")));
- (id<MDTMFlow>)fuseContext:(id<MDTMKotlinCoroutineContext>)context capacity:(int32_t)capacity onBufferOverflow:(MDTMBufferOverflow *)onBufferOverflow __attribute__((swift_name("fuse(context:capacity:onBufferOverflow:)")));
- (id<MDTMReceiveChannel>)produceImplScope:(id<MDTMCoroutineScope>)scope __attribute__((swift_name("produceImpl(scope:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t capacity __attribute__((swift_name("capacity")));
@property (readonly) id<MDTMKotlinCoroutineContext> context __attribute__((swift_name("context")));
@property (readonly) MDTMBufferOverflow *onBufferOverflow __attribute__((swift_name("onBufferOverflow")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SendingCollector")))
@interface MDTMSendingCollector<T> : MDTMBase <MDTMFlowCollector>
- (instancetype)initWithChannel:(id<MDTMSendChannel>)channel __attribute__((swift_name("init(channel:)"))) __attribute__((objc_designated_initializer));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)emitValue:(T _Nullable)value completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emit(value:completionHandler:)")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("LockFreeLinkedListNode")))
@interface MDTMLockFreeLinkedListNode : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (BOOL)addLastNode:(MDTMLockFreeLinkedListNode *)node permissionsBitmask:(int32_t)permissionsBitmask __attribute__((swift_name("addLast(node:permissionsBitmask:)")));
- (BOOL)addOneIfEmptyNode:(MDTMLockFreeLinkedListNode *)node __attribute__((swift_name("addOneIfEmpty(node:)")));
- (void)closeForbiddenElementsBit:(int32_t)forbiddenElementsBit __attribute__((swift_name("close(forbiddenElementsBit:)")));
- (BOOL)remove __attribute__((swift_name("remove()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL isRemoved __attribute__((swift_name("isRemoved")));
@property (readonly, getter=next_) id next __attribute__((swift_name("next")));
@property (readonly) MDTMLockFreeLinkedListNode *nextNode __attribute__((swift_name("nextNode")));
@property (readonly) MDTMLockFreeLinkedListNode *prevNode __attribute__((swift_name("prevNode")));
@end

__attribute__((swift_name("LockFreeLinkedListHead")))
@interface MDTMLockFreeLinkedListHead : MDTMLockFreeLinkedListNode
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)forEachBlock:(void (^)(MDTMLockFreeLinkedListNode *))block __attribute__((swift_name("forEach(block:)")));
- (BOOL)remove __attribute__((swift_name("remove()")));
@property (readonly) BOOL isRemoved __attribute__((swift_name("isRemoved")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("MainDispatcherFactory")))
@protocol MDTMMainDispatcherFactory
@required
- (MDTMMainCoroutineDispatcher *)createDispatcherAllFactories:(NSArray<id<MDTMMainDispatcherFactory>> *)allFactories __attribute__((swift_name("createDispatcher(allFactories:)")));
- (NSString * _Nullable)hintOnError __attribute__((swift_name("hintOnError()")));
@property (readonly) int32_t loadPriority __attribute__((swift_name("loadPriority")));
@end

__attribute__((swift_name("AtomicfuSynchronizedObject")))
@interface MDTMAtomicfuSynchronizedObject : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)lock __attribute__((swift_name("lock()")));
- (BOOL)tryLock __attribute__((swift_name("tryLock()")));
- (void)unlock __attribute__((swift_name("unlock()")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("ThreadSafeHeap")))
@interface MDTMThreadSafeHeap<T> : MDTMAtomicfuSynchronizedObject
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)addLastNode:(T)node __attribute__((swift_name("addLast(node:)")));
- (BOOL)addLastIfNode:(T)node cond:(MDTMBoolean *(^)(T _Nullable))cond __attribute__((swift_name("addLastIf(node:cond:)")));
- (T _Nullable)findPredicate:(MDTMBoolean *(^)(T))predicate __attribute__((swift_name("find(predicate:)")));
- (T _Nullable)peek __attribute__((swift_name("peek()")));
- (BOOL)removeNode:(T)node __attribute__((swift_name("remove(node:)")));
- (T _Nullable)removeFirstIfPredicate:(MDTMBoolean *(^)(T))predicate __attribute__((swift_name("removeFirstIf(predicate:)")));
- (T _Nullable)removeFirstOrNull __attribute__((swift_name("removeFirstOrNull()")));
@property (readonly) BOOL isEmpty __attribute__((swift_name("isEmpty")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("ThreadSafeHeapNode")))
@protocol MDTMThreadSafeHeapNode
@required
@property MDTMThreadSafeHeap<id> * _Nullable heap __attribute__((swift_name("heap")));
@property int32_t index __attribute__((swift_name("index")));
@end

__attribute__((swift_name("SelectBuilder")))
@protocol MDTMSelectBuilder
@required
- (void)invoke:(id<MDTMSelectClause0>)receiver block:(id<MDTMKotlinSuspendFunction0>)block __attribute__((swift_name("invoke(_:block:)")));
- (void)invoke:(id<MDTMSelectClause1>)receiver block_:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("invoke(_:block_:)")));
- (void)invoke:(id<MDTMSelectClause2>)receiver block__:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("invoke(_:block__:)")));
- (void)invoke:(id<MDTMSelectClause2>)receiver param:(id _Nullable)param block:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("invoke(_:param:block:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
- (void)onTimeoutTimeMillis:(int64_t)timeMillis block:(id<MDTMKotlinSuspendFunction0>)block __attribute__((swift_name("onTimeout(timeMillis:block:)"))) __attribute__((unavailable("Replaced with the same extension function")));
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("SelectClause")))
@protocol MDTMSelectClause
@required
@property (readonly) id clauseObject __attribute__((swift_name("clauseObject")));
@property (readonly) MDTMKotlinUnit *(^(^ _Nullable onCancellationConstructor)(id<MDTMSelectInstance>, id _Nullable, id _Nullable))(MDTMKotlinThrowable *, id _Nullable, id<MDTMKotlinCoroutineContext>) __attribute__((swift_name("onCancellationConstructor")));
@property (readonly) id _Nullable (^processResFunc)(id, id _Nullable, id _Nullable) __attribute__((swift_name("processResFunc")));
@property (readonly) void (^regFunc)(id, id<MDTMSelectInstance>, id _Nullable) __attribute__((swift_name("regFunc")));
@end

__attribute__((swift_name("SelectClause0")))
@protocol MDTMSelectClause0 <MDTMSelectClause>
@required
@end

__attribute__((swift_name("SelectClause1")))
@protocol MDTMSelectClause1 <MDTMSelectClause>
@required
@end

__attribute__((swift_name("SelectClause2")))
@protocol MDTMSelectClause2 <MDTMSelectClause>
@required
@end


/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
__attribute__((swift_name("SelectInstance")))
@protocol MDTMSelectInstance
@required
- (void)disposeOnCompletionDisposableHandle:(id<MDTMDisposableHandle>)disposableHandle __attribute__((swift_name("disposeOnCompletion(disposableHandle:)")));
- (void)selectInRegistrationPhaseInternalResult:(id _Nullable)internalResult __attribute__((swift_name("selectInRegistrationPhase(internalResult:)")));
- (BOOL)trySelectClauseObject:(id)clauseObject result:(id _Nullable)result __attribute__((swift_name("trySelect(clauseObject:result:)")));
@property (readonly) id<MDTMKotlinCoroutineContext> context __attribute__((swift_name("context")));
@end

__attribute__((swift_name("Mutex")))
@protocol MDTMMutex
@required
- (BOOL)holdsLockOwner:(id)owner __attribute__((swift_name("holdsLock(owner:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)lockOwner:(id _Nullable)owner completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("lock(owner:completionHandler:)")));
- (BOOL)tryLockOwner:(id _Nullable)owner __attribute__((swift_name("tryLock(owner:)")));
- (void)unlockOwner:(id _Nullable)owner __attribute__((swift_name("unlock(owner:)")));
@property (readonly) BOOL isLocked __attribute__((swift_name("isLocked")));
@property (readonly) id<MDTMSelectClause2> onLock __attribute__((swift_name("onLock"))) __attribute__((deprecated("Mutex.onLock deprecated without replacement. For additional details please refer to #2794")));
@end

__attribute__((swift_name("Semaphore")))
@protocol MDTMSemaphore
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)acquireWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("acquire(completionHandler:)")));
- (void)release_ __attribute__((swift_name("release()")));
- (BOOL)tryAcquire __attribute__((swift_name("tryAcquire()")));
@property (readonly) int32_t availablePermits __attribute__((swift_name("availablePermits")));
@end

@interface MDTMHttpClient (Extensions)

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)cookiesUrl:(MDTMKtor_httpUrl *)url completionHandler:(void (^)(NSArray<MDTMKtor_httpCookie *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("cookies(url:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)cookiesUrlString:(NSString *)urlString completionHandler:(void (^)(NSArray<MDTMKtor_httpCookie *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("cookies(urlString:completionHandler:)")));
- (void)defaultTransformers __attribute__((swift_name("defaultTransformers()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("delete(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("delete(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("delete(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("delete(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("get(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("get(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("get(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("get(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)headBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("head(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)headBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("head(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)headUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("head(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)headUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("head(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)optionsBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("options(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)optionsBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("options(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)optionsUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("options(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)optionsUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("options(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)patchBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("patch(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)patchBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("patch(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)patchUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("patch(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)patchUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("patch(urlString:block:completionHandler:)")));
- (id)pluginPlugin:(id<MDTMHttpClientPlugin>)plugin __attribute__((swift_name("plugin(plugin:)")));
- (id _Nullable)pluginOrNullPlugin:(id<MDTMHttpClientPlugin>)plugin __attribute__((swift_name("pluginOrNull(plugin:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)postBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("post(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)postBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("post(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)postUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("post(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)postUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("post(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareDeleteBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareDelete(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareDeleteBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareDelete(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareDeleteUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareDelete(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareDeleteUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareDelete(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareFormFormParameters:(id<MDTMKtor_httpParameters>)formParameters encodeInQuery:(BOOL)encodeInQuery block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareForm(formParameters:encodeInQuery:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareFormUrl:(NSString *)url formParameters:(id<MDTMKtor_httpParameters>)formParameters encodeInQuery:(BOOL)encodeInQuery block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareForm(url:formParameters:encodeInQuery:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareFormWithBinaryDataFormData:(NSArray<MDTMKtor_httpPartData *> *)formData block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareFormWithBinaryData(formData:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareFormWithBinaryDataUrl:(NSString *)url formData:(NSArray<MDTMKtor_httpPartData *> *)formData block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareFormWithBinaryData(url:formData:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareGetBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareGet(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareGetBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareGet(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareGetUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareGet(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareGetUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareGet(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareHeadBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareHead(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareHeadBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareHead(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareHeadUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareHead(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareHeadUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareHead(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareOptionsBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareOptions(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareOptionsBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareOptions(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareOptionsUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareOptions(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareOptionsUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareOptions(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)preparePatchBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("preparePatch(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)preparePatchBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("preparePatch(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)preparePatchUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("preparePatch(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)preparePatchUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("preparePatch(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)preparePostBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("preparePost(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)preparePostBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("preparePost(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)preparePostUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("preparePost(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)preparePostUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("preparePost(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)preparePutBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("preparePut(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)preparePutBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("preparePut(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)preparePutUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("preparePut(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)preparePutUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("preparePut(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareRequestBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareRequest(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareRequestBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareRequest(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareRequestUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareRequest(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)prepareRequestUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpStatement * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("prepareRequest(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)putBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("put(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)putBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("put(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)putUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("put(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)putUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("put(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)requestBuilder:(MDTMHttpRequestBuilder *)builder completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("request(builder:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)requestBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("request(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)requestUrl:(MDTMKtor_httpUrl *)url block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("request(url:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)requestUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("request(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)serverSentEventsRequest:(void (^)(MDTMHttpRequestBuilder *))request reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("serverSentEvents(request:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)serverSentEventsRequest:(void (^)(MDTMHttpRequestBuilder *))request deserialize:(id _Nullable (^)(MDTMKtor_utilsTypeInfo *, NSString *))deserialize reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("serverSentEvents(request:deserialize:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)serverSentEventsUrlString:(NSString *)urlString reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents request:(void (^)(MDTMHttpRequestBuilder *))request block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("serverSentEvents(urlString:reconnectionTime:showCommentEvents:showRetryEvents:request:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)serverSentEventsUrlString:(NSString *)urlString deserialize:(id _Nullable (^)(MDTMKtor_utilsTypeInfo *, NSString *))deserialize reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents request:(void (^)(MDTMHttpRequestBuilder *))request block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("serverSentEvents(urlString:deserialize:reconnectionTime:showCommentEvents:showRetryEvents:request:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)serverSentEventsScheme:(NSString * _Nullable)scheme host:(NSString * _Nullable)host port:(MDTMInt * _Nullable)port path:(NSString * _Nullable)path reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents request:(void (^)(MDTMHttpRequestBuilder *))request block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("serverSentEvents(scheme:host:port:path:reconnectionTime:showCommentEvents:showRetryEvents:request:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)serverSentEventsScheme:(NSString * _Nullable)scheme host:(NSString * _Nullable)host port:(MDTMInt * _Nullable)port path:(NSString * _Nullable)path deserialize:(id _Nullable (^)(MDTMKtor_utilsTypeInfo *, NSString *))deserialize reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents request:(void (^)(MDTMHttpRequestBuilder *))request block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("serverSentEvents(scheme:host:port:path:deserialize:reconnectionTime:showCommentEvents:showRetryEvents:request:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)serverSentEventsSessionReconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMClientSSESession * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("serverSentEventsSession(reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)serverSentEventsSessionDeserialize:(id _Nullable (^)(MDTMKtor_utilsTypeInfo *, NSString *))deserialize reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMClientSSESessionWithDeserialization * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("serverSentEventsSession(deserialize:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)serverSentEventsSessionUrlString:(NSString *)urlString reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMClientSSESession * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("serverSentEventsSession(urlString:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)serverSentEventsSessionUrlString:(NSString *)urlString deserialize:(id _Nullable (^)(MDTMKtor_utilsTypeInfo *, NSString *))deserialize reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMClientSSESessionWithDeserialization * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("serverSentEventsSession(urlString:deserialize:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)serverSentEventsSessionScheme:(NSString * _Nullable)scheme host:(NSString * _Nullable)host port:(MDTMInt * _Nullable)port path:(NSString * _Nullable)path reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMClientSSESession * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("serverSentEventsSession(scheme:host:port:path:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)serverSentEventsSessionScheme:(NSString * _Nullable)scheme host:(NSString * _Nullable)host port:(MDTMInt * _Nullable)port path:(NSString * _Nullable)path deserialize:(id _Nullable (^)(MDTMKtor_utilsTypeInfo *, NSString *))deserialize reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMClientSSESessionWithDeserialization * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("serverSentEventsSession(scheme:host:port:path:deserialize:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sseRequest:(void (^)(MDTMHttpRequestBuilder *))request reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("sse(request:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sseRequest:(void (^)(MDTMHttpRequestBuilder *))request deserialize:(id _Nullable (^)(MDTMKtor_utilsTypeInfo *, NSString *))deserialize reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("sse(request:deserialize:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sseUrlString:(NSString *)urlString request:(void (^)(MDTMHttpRequestBuilder *))request reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("sse(urlString:request:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sseUrlString:(NSString *)urlString request:(void (^)(MDTMHttpRequestBuilder *))request deserialize:(id _Nullable (^)(MDTMKtor_utilsTypeInfo *, NSString *))deserialize reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("sse(urlString:request:deserialize:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sseScheme:(NSString * _Nullable)scheme host:(NSString * _Nullable)host port:(MDTMInt * _Nullable)port path:(NSString * _Nullable)path request:(void (^)(MDTMHttpRequestBuilder *))request reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("sse(scheme:host:port:path:request:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sseScheme:(NSString * _Nullable)scheme host:(NSString * _Nullable)host port:(MDTMInt * _Nullable)port path:(NSString * _Nullable)path request:(void (^)(MDTMHttpRequestBuilder *))request deserialize:(id _Nullable (^)(MDTMKtor_utilsTypeInfo *, NSString *))deserialize reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("sse(scheme:host:port:path:request:deserialize:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sseSessionReconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMClientSSESession * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("sseSession(reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sseSessionDeserialize:(id _Nullable (^)(MDTMKtor_utilsTypeInfo *, NSString *))deserialize reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMClientSSESessionWithDeserialization * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("sseSession(deserialize:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sseSessionUrlString:(NSString *)urlString reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMClientSSESession * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("sseSession(urlString:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sseSessionUrlString:(NSString *)urlString deserialize:(id _Nullable (^)(MDTMKtor_utilsTypeInfo *, NSString *))deserialize reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMClientSSESessionWithDeserialization * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("sseSession(urlString:deserialize:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sseSessionScheme:(NSString * _Nullable)scheme host:(NSString * _Nullable)host port:(MDTMInt * _Nullable)port path:(NSString * _Nullable)path reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMClientSSESession * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("sseSession(scheme:host:port:path:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sseSessionScheme:(NSString * _Nullable)scheme host:(NSString * _Nullable)host port:(MDTMInt * _Nullable)port path:(NSString * _Nullable)path deserialize:(id _Nullable (^)(MDTMKtor_utilsTypeInfo *, NSString *))deserialize reconnectionTime:(id _Nullable)reconnectionTime showCommentEvents:(MDTMBoolean * _Nullable)showCommentEvents showRetryEvents:(MDTMBoolean * _Nullable)showRetryEvents block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMClientSSESessionWithDeserialization * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("sseSession(scheme:host:port:path:deserialize:reconnectionTime:showCommentEvents:showRetryEvents:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)submitFormFormParameters:(id<MDTMKtor_httpParameters>)formParameters encodeInQuery:(BOOL)encodeInQuery block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("submitForm(formParameters:encodeInQuery:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)submitFormUrl:(NSString *)url formParameters:(id<MDTMKtor_httpParameters>)formParameters encodeInQuery:(BOOL)encodeInQuery block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("submitForm(url:formParameters:encodeInQuery:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)submitFormWithBinaryDataFormData:(NSArray<MDTMKtor_httpPartData *> *)formData block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("submitFormWithBinaryData(formData:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)submitFormWithBinaryDataUrl:(NSString *)url formData:(NSArray<MDTMKtor_httpPartData *> *)formData block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMHttpResponse * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("submitFormWithBinaryData(url:formData:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)webSocketRequest:(void (^)(MDTMHttpRequestBuilder *))request block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("webSocket(request:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)webSocketUrlString:(NSString *)urlString request:(void (^)(MDTMHttpRequestBuilder *))request block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("webSocket(urlString:request:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)webSocketMethod:(MDTMKtor_httpHttpMethod *)method host:(NSString * _Nullable)host port:(MDTMInt * _Nullable)port path:(NSString * _Nullable)path request:(void (^)(MDTMHttpRequestBuilder *))request block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("webSocket(method:host:port:path:request:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)webSocketSessionBlock:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMDefaultClientWebSocketSession * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("webSocketSession(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)webSocketSessionUrlString:(NSString *)urlString block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMDefaultClientWebSocketSession * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("webSocketSession(urlString:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)webSocketSessionMethod:(MDTMKtor_httpHttpMethod *)method host:(NSString * _Nullable)host port:(MDTMInt * _Nullable)port path:(NSString * _Nullable)path block:(void (^)(MDTMHttpRequestBuilder *))block completionHandler:(void (^)(MDTMDefaultClientWebSocketSession * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("webSocketSession(method:host:port:path:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)wsRequest:(void (^)(MDTMHttpRequestBuilder *))request block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("ws(request:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)wsUrlString:(NSString *)urlString request:(void (^)(MDTMHttpRequestBuilder *))request block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("ws(urlString:request:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)wsMethod:(MDTMKtor_httpHttpMethod *)method host:(NSString * _Nullable)host port:(MDTMInt * _Nullable)port path:(NSString * _Nullable)path request:(void (^)(MDTMHttpRequestBuilder *))request block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("ws(method:host:port:path:request:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)wssRequest:(void (^)(MDTMHttpRequestBuilder *))request block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("wss(request:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)wssUrlString:(NSString *)urlString request:(void (^)(MDTMHttpRequestBuilder *))request block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("wss(urlString:request:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)wssMethod:(MDTMKtor_httpHttpMethod *)method host:(NSString * _Nullable)host port:(MDTMInt * _Nullable)port path:(NSString * _Nullable)path request:(void (^)(MDTMHttpRequestBuilder *))request block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("wss(method:host:port:path:request:block:completionHandler:)")));
@end

@interface MDTMHttpClientConfig (Extensions)
- (void)BrowserUserAgent __attribute__((swift_name("BrowserUserAgent()")));
- (void)CharsetsBlock:(void (^)(MDTMHttpPlainTextConfig *))block __attribute__((swift_name("Charsets(block:)")));
- (void)CurlUserAgent __attribute__((swift_name("CurlUserAgent()")));
- (void)HttpResponseValidatorBlock:(void (^)(MDTMHttpCallValidatorConfig *))block __attribute__((swift_name("HttpResponseValidator(block:)")));
- (void)ResponseObserverBlock:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("ResponseObserver(block:)")));
- (void)SSEConfig:(void (^)(MDTMSSEConfig *))config __attribute__((swift_name("SSE(config:)")));
- (void)WebSocketsConfig:(void (^)(MDTMWebSocketsConfig *))config __attribute__((swift_name("WebSockets(config:)")));
- (void)addDefaultResponseValidation __attribute__((swift_name("addDefaultResponseValidation()")));
- (void)defaultRequestBlock:(void (^)(MDTMDefaultRequestDefaultRequestBuilder *))block __attribute__((swift_name("defaultRequest(block:)")));
@end

@interface MDTMHttpClientCall (Extensions)

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyWithCompletionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("body(completionHandler:)")));
- (MDTMHttpClientCall *)replaceResponseHeaders:(id<MDTMKtor_httpHeaders>)headers content:(id<MDTMKtor_ioByteReadChannel> (^)(MDTMHttpResponse *))content __attribute__((swift_name("replaceResponse(headers:content:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)saveWithCompletionHandler:(void (^)(MDTMHttpClientCall * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("save(completionHandler:)")));
- (MDTMHttpClientCall *)wrapContent:(id<MDTMKtor_ioByteReadChannel>)content headers:(id<MDTMKtor_httpHeaders>)headers __attribute__((swift_name("wrap(content:headers:)"))) __attribute__((deprecated("Use 'replaceResponse' instead.")));
- (MDTMHttpClientCall *)wrapWithContentContent:(id<MDTMKtor_ioByteReadChannel>)content __attribute__((swift_name("wrapWithContent(content:)"))) __attribute__((deprecated("Use 'replaceResponse' instead.")));
- (MDTMHttpClientCall *)wrapWithContentBlock:(id<MDTMKtor_ioByteReadChannel> (^)(void))block __attribute__((swift_name("wrapWithContent(block:)"))) __attribute__((deprecated("Use 'replaceResponse' instead.")));
@end

@interface MDTMProxyBuilder (Extensions)
- (MDTMProxyConfig *)httpUrlString:(NSString *)urlString __attribute__((swift_name("http(urlString:)")));
@end

@interface MDTMProxyConfig (Extensions)
- (MDTMKtor_utilsNetworkAddress *)resolveAddress __attribute__((swift_name("resolveAddress()")));
@property (readonly) MDTMProxyType *type __attribute__((swift_name("type")));
@end

@interface MDTMDefaultClientWebSocketSession (Extensions)

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)receiveDeserializedWithCompletionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("receiveDeserialized(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)receiveDeserializedTypeInfo:(MDTMKtor_utilsTypeInfo *)typeInfo completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("receiveDeserialized(typeInfo:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sendSerializedData:(id _Nullable)data completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("sendSerialized(data:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)sendSerializedData:(id _Nullable)data typeInfo:(MDTMKtor_utilsTypeInfo *)typeInfo completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("sendSerialized(data:typeInfo:completionHandler:)")));
@property (readonly) id<MDTMKtor_serializationWebsocketContentConverter> _Nullable converter __attribute__((swift_name("converter")));
@end

@interface MDTMWebSockets (Extensions)
@property (readonly) id _Nullable pingInterval __attribute__((swift_name("pingInterval")));
@end

@interface MDTMWebSocketsConfig (Extensions)
@property id _Nullable pingInterval __attribute__((swift_name("pingInterval")));
@end

@interface MDTMHttpRequestBuilder (Extensions)
- (void)excludeContentType:(MDTMKotlinArray<MDTMKtor_httpContentType *> *)contentType __attribute__((swift_name("exclude(contentType:)")));
- (void)onDownloadListener:(id<MDTMProgressListener> _Nullable)listener __attribute__((swift_name("onDownload(listener:)")));
- (void)onUploadListener:(id<MDTMProgressListener> _Nullable)listener __attribute__((swift_name("onUpload(listener:)")));
- (void)parameterKey:(NSString *)key value:(id _Nullable)value __attribute__((swift_name("parameter(key:value:)")));
- (void)retryBlock:(void (^)(MDTMHttpRequestRetryConfig *))block __attribute__((swift_name("retry(block:)")));
- (void)setBodyBody:(id _Nullable)body __attribute__((swift_name("setBody(body:)")));
- (void)setBodyBody:(id _Nullable)body bodyType:(MDTMKtor_utilsTypeInfo *)bodyType __attribute__((swift_name("setBody(body:bodyType:)")));
- (void)skipSavingBody __attribute__((swift_name("skipSavingBody()"))) __attribute__((deprecated("Skipping of body saving for a specific request is no longer allowed.\nUse client.prepareRequest(...).execute { ... } syntax to prevent saving the body in memory.\n\nThis API is deprecated and will be removed in Ktor 4.0.0\nIf you were relying on this functionality, share your use case by commenting on this issue: https://youtrack.jetbrains.com/issue/KTOR-8367/")));
- (MDTMHttpRequestBuilder *)takeFromRequest:(id<MDTMHttpRequest>)request __attribute__((swift_name("takeFrom(request:)")));
- (MDTMHttpRequestBuilder *)takeFromRequest_:(MDTMHttpRequestData *)request __attribute__((swift_name("takeFrom(request_:)")));
- (void)timeoutBlock:(void (^)(MDTMHttpTimeoutConfig *))block __attribute__((swift_name("timeout(block:)")));
- (void)unixSocketPath:(NSString *)path __attribute__((swift_name("unixSocket(path:)")));
- (void)urlUrl:(MDTMKtor_httpUrl *)url __attribute__((swift_name("url(url:)")));
- (void)urlBlock_:(void (^)(MDTMKtor_httpURLBuilder *))block __attribute__((swift_name("url(block_:)")));
- (void)urlUrlString:(NSString *)urlString __attribute__((swift_name("url(urlString:)")));
- (void)urlScheme:(NSString * _Nullable)scheme host:(NSString * _Nullable)host port:(MDTMInt * _Nullable)port path:(NSString * _Nullable)path block:(void (^)(MDTMKtor_httpURLBuilder *))block __attribute__((swift_name("url(scheme:host:port:path:block:)")));
@property BOOL expectSuccess __attribute__((swift_name("expectSuccess")));
@property NSString *host __attribute__((swift_name("host")));
@property int32_t port __attribute__((swift_name("port")));
@end

@interface MDTMHttpRequestBuilderCompanion (Extensions)
- (MDTMHttpRequestBuilder *)invokeBlock:(void (^)(MDTMKtor_httpURLBuilder *))block __attribute__((swift_name("invoke(block:)")));
- (MDTMHttpRequestBuilder *)invokeScheme:(NSString * _Nullable)scheme host:(NSString * _Nullable)host port:(MDTMInt * _Nullable)port path:(NSString * _Nullable)path block:(void (^)(MDTMKtor_httpURLBuilder *))block __attribute__((swift_name("invoke(scheme:host:port:path:block:)")));
@end

@interface MDTMHttpRequestData (Extensions)
- (void)forEachHeaderBlock:(void (^)(NSString *, NSString *))block __attribute__((swift_name("forEachHeader(block:)")));
- (BOOL)isSseReconnectionRequest __attribute__((swift_name("isSseReconnectionRequest()")));
- (BOOL)isSseRequest __attribute__((swift_name("isSseRequest()")));
- (BOOL)isUpgradeRequest __attribute__((swift_name("isUpgradeRequest()")));
@end

@interface MDTMFormBuilder (Extensions)
- (void)appendKey:(NSString *)key headers:(id<MDTMKtor_httpHeaders>)headers size:(MDTMLong * _Nullable)size bodyBuilder:(void (^)(id<MDTMKotlinx_io_coreSink>))bodyBuilder __attribute__((swift_name("append(key:headers:size:bodyBuilder:)")));
- (void)appendKey:(NSString *)key filename:(NSString *)filename contentType:(MDTMKtor_httpContentType * _Nullable)contentType size:(MDTMLong * _Nullable)size bodyBuilder:(void (^)(id<MDTMKotlinx_io_coreSink>))bodyBuilder __attribute__((swift_name("append(key:filename:contentType:size:bodyBuilder:)")));
@end

@interface MDTMHttpResponse (Extensions)

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyWithCompletionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("body(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyTypeInfo:(MDTMKtor_utilsTypeInfo *)typeInfo completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("body(typeInfo:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyAsBytesWithCompletionHandler:(void (^)(MDTMKotlinByteArray * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("bodyAsBytes(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyAsChannelWithCompletionHandler:(void (^)(id<MDTMKtor_ioByteReadChannel> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("bodyAsChannel(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)bodyAsTextFallbackCharset:(MDTMKtor_ioCharset *)fallbackCharset completionHandler:(void (^)(NSString * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("bodyAsText(fallbackCharset:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)discardRemainingWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("discardRemaining(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readBytesWithCompletionHandler:(void (^)(MDTMKotlinByteArray * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readBytes(completionHandler:)"))) __attribute__((deprecated("This method was renamed to readRawBytes() to reflect what it does.")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readBytesCount:(int32_t)count completionHandler:(void (^)(MDTMKotlinByteArray * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readBytes(count:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readRawBytesWithCompletionHandler:(void (^)(MDTMKotlinByteArray * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readRawBytes(completionHandler:)")));
@property (readonly) id<MDTMKtor_ioByteReadChannel> content_ __attribute__((swift_name("content_"))) __attribute__((deprecated("This method was renamed to readRawBytes() to reflect what it does.")));
@property (readonly) BOOL isSaved __attribute__((swift_name("isSaved")));
@property (readonly) id<MDTMHttpRequest> request __attribute__((swift_name("request")));
@end

__attribute__((swift_name("Ktor_ioJvmSerializable")))
@protocol MDTMKtor_ioJvmSerializable
@required
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpCookie")))
@interface MDTMKtor_httpCookie : MDTMBase <MDTMKtor_ioJvmSerializable>
- (instancetype)initWithName:(NSString *)name value:(NSString *)value encoding:(MDTMKtor_httpCookieEncoding *)encoding maxAge:(MDTMInt * _Nullable)maxAge expires:(MDTMKtor_utilsGMTDate * _Nullable)expires domain:(NSString * _Nullable)domain path:(NSString * _Nullable)path secure:(BOOL)secure httpOnly:(BOOL)httpOnly extensions:(NSDictionary<NSString *, id> *)extensions __attribute__((swift_name("init(name:value:encoding:maxAge:expires:domain:path:secure:httpOnly:extensions:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMKtor_httpCookieCompanion *companion __attribute__((swift_name("companion")));
- (MDTMKtor_httpCookie *)doCopyName:(NSString *)name value:(NSString *)value encoding:(MDTMKtor_httpCookieEncoding *)encoding maxAge:(MDTMInt * _Nullable)maxAge expires:(MDTMKtor_utilsGMTDate * _Nullable)expires domain:(NSString * _Nullable)domain path:(NSString * _Nullable)path secure:(BOOL)secure httpOnly:(BOOL)httpOnly extensions:(NSDictionary<NSString *, id> *)extensions __attribute__((swift_name("doCopy(name:value:encoding:maxAge:expires:domain:path:secure:httpOnly:extensions:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable domain __attribute__((swift_name("domain")));
@property (readonly) MDTMKtor_httpCookieEncoding *encoding __attribute__((swift_name("encoding")));
@property (readonly) MDTMKtor_utilsGMTDate * _Nullable expires __attribute__((swift_name("expires")));
@property (readonly) NSDictionary<NSString *, id> *extensions __attribute__((swift_name("extensions")));
@property (readonly) BOOL httpOnly __attribute__((swift_name("httpOnly")));
@property (readonly) MDTMInt * _Nullable maxAge __attribute__((swift_name("maxAge")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) NSString * _Nullable path __attribute__((swift_name("path")));
@property (readonly) BOOL secure __attribute__((swift_name("secure")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

@interface MDTMKtor_httpCookie (Extensions)
- (MDTMKtor_httpCookie *)fillDefaultsRequestUrl:(MDTMKtor_httpUrl *)requestUrl __attribute__((swift_name("fillDefaults(requestUrl:)")));
- (BOOL)matchesRequestUrl:(MDTMKtor_httpUrl *)requestUrl __attribute__((swift_name("matches(requestUrl:)")));
@end

__attribute__((swift_name("Ktor_utilsStringValuesBuilder")))
@protocol MDTMKtor_utilsStringValuesBuilder
@required
- (void)appendName:(NSString *)name value:(NSString *)value __attribute__((swift_name("append(name:value:)")));
- (void)appendAllStringValues:(id<MDTMKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendAll(stringValues:)")));
- (void)appendAllName:(NSString *)name values:(id)values __attribute__((swift_name("appendAll(name:values:)")));
- (void)appendMissingStringValues:(id<MDTMKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendMissing(stringValues:)")));
- (void)appendMissingName:(NSString *)name values:(id)values __attribute__((swift_name("appendMissing(name:values:)")));
- (id<MDTMKtor_utilsStringValues>)build __attribute__((swift_name("build()")));
- (void)clear __attribute__((swift_name("clear()")));
- (BOOL)containsName:(NSString *)name __attribute__((swift_name("contains(name:)")));
- (BOOL)containsName:(NSString *)name value:(NSString *)value __attribute__((swift_name("contains(name:value:)")));
- (NSSet<id<MDTMKotlinMapEntry>> *)entries __attribute__((swift_name("entries()")));
- (NSString * _Nullable)getName:(NSString *)name __attribute__((swift_name("get(name:)")));
- (NSArray<NSString *> * _Nullable)getAllName:(NSString *)name __attribute__((swift_name("getAll(name:)")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
- (NSSet<NSString *> *)names __attribute__((swift_name("names()")));
- (void)removeName:(NSString *)name __attribute__((swift_name("remove(name:)")));
- (BOOL)removeName:(NSString *)name value:(NSString *)value __attribute__((swift_name("remove(name:value:)")));
- (void)removeKeysWithNoEntries __attribute__((swift_name("removeKeysWithNoEntries()")));
- (void)setName:(NSString *)name value:(NSString *)value __attribute__((swift_name("set(name:value:)")));
@property (readonly) BOOL caseInsensitiveName __attribute__((swift_name("caseInsensitiveName")));
@end

__attribute__((swift_name("Ktor_utilsStringValuesBuilderImpl")))
@interface MDTMKtor_utilsStringValuesBuilderImpl : MDTMBase <MDTMKtor_utilsStringValuesBuilder>
- (instancetype)initWithCaseInsensitiveName:(BOOL)caseInsensitiveName size:(int32_t)size __attribute__((swift_name("init(caseInsensitiveName:size:)"))) __attribute__((objc_designated_initializer));
- (void)appendName:(NSString *)name value:(NSString *)value __attribute__((swift_name("append(name:value:)")));
- (void)appendAllStringValues:(id<MDTMKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendAll(stringValues:)")));
- (void)appendAllName:(NSString *)name values:(id)values __attribute__((swift_name("appendAll(name:values:)")));
- (void)appendMissingStringValues:(id<MDTMKtor_utilsStringValues>)stringValues __attribute__((swift_name("appendMissing(stringValues:)")));
- (void)appendMissingName:(NSString *)name values:(id)values __attribute__((swift_name("appendMissing(name:values:)")));
- (id<MDTMKtor_utilsStringValues>)build __attribute__((swift_name("build()")));
- (void)clear __attribute__((swift_name("clear()")));
- (BOOL)containsName:(NSString *)name __attribute__((swift_name("contains(name:)")));
- (BOOL)containsName:(NSString *)name value:(NSString *)value __attribute__((swift_name("contains(name:value:)")));
- (NSSet<id<MDTMKotlinMapEntry>> *)entries __attribute__((swift_name("entries()")));
- (NSString * _Nullable)getName:(NSString *)name __attribute__((swift_name("get(name:)")));
- (NSArray<NSString *> * _Nullable)getAllName:(NSString *)name __attribute__((swift_name("getAll(name:)")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
- (NSSet<NSString *> *)names __attribute__((swift_name("names()")));
- (void)removeName:(NSString *)name __attribute__((swift_name("remove(name:)")));
- (BOOL)removeName:(NSString *)name value:(NSString *)value __attribute__((swift_name("remove(name:value:)")));
- (void)removeKeysWithNoEntries __attribute__((swift_name("removeKeysWithNoEntries()")));
- (void)setName:(NSString *)name value:(NSString *)value __attribute__((swift_name("set(name:value:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateNameName:(NSString *)name __attribute__((swift_name("validateName(name:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateValueValue:(NSString *)value __attribute__((swift_name("validateValue(value:)")));
@property (readonly) BOOL caseInsensitiveName __attribute__((swift_name("caseInsensitiveName")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) MDTMMutableDictionary<NSString *, NSMutableArray<NSString *> *> *values __attribute__((swift_name("values")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHeadersBuilder")))
@interface MDTMKtor_httpHeadersBuilder : MDTMKtor_utilsStringValuesBuilderImpl
- (instancetype)initWithSize:(int32_t)size __attribute__((swift_name("init(size:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCaseInsensitiveName:(BOOL)caseInsensitiveName size:(int32_t)size __attribute__((swift_name("init(caseInsensitiveName:size:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (id<MDTMKtor_httpHeaders>)build __attribute__((swift_name("build()")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateNameName:(NSString *)name __attribute__((swift_name("validateName(name:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)validateValueValue:(NSString *)value __attribute__((swift_name("validateValue(value:)")));
@end

@interface MDTMKtor_httpHeadersBuilder (Extensions)
- (void)dropCompressionHeadersMethod:(MDTMKtor_httpHttpMethod *)method attributes:(id<MDTMKtor_utilsAttributes>)attributes alwaysRemove:(BOOL)alwaysRemove __attribute__((swift_name("dropCompressionHeaders(method:attributes:alwaysRemove:)")));
@end

@interface MDTMKtor_httpOutgoingContent (Extensions)
- (MDTMKtor_httpOutgoingContent *)wrapHeadersBlock:(id<MDTMKtor_httpHeaders> (^)(id<MDTMKtor_httpHeaders>))block __attribute__((swift_name("wrapHeaders(block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface MDTMKotlinArray<T> : MDTMBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(MDTMInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<MDTMKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

@interface MDTMKotlinArray (Extensions)
- (id<MDTMFlow>)asFlow __attribute__((swift_name("asFlow()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinIntArray")))
@interface MDTMKotlinIntArray : MDTMBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(MDTMInt *(^)(MDTMInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int32_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (MDTMKotlinIntIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int32_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

@interface MDTMKotlinIntArray (Extensions)
- (id<MDTMFlow>)asFlow __attribute__((swift_name("asFlow()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinLongArray")))
@interface MDTMKotlinLongArray : MDTMBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(MDTMLong *(^)(MDTMInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int64_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (MDTMKotlinLongIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int64_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

@interface MDTMKotlinLongArray (Extensions)
- (id<MDTMFlow>)asFlow __attribute__((swift_name("asFlow()")));
@end

@interface MDTMKotlinThrowable (Extensions)
- (MDTMKotlinThrowable *)unwrapCancellationException __attribute__((swift_name("unwrapCancellationException()")));
@end

__attribute__((swift_name("KotlinIntProgression")))
@interface MDTMKotlinIntProgression : MDTMBase <MDTMKotlinIterable>
@property (class, readonly, getter=companion) MDTMKotlinIntProgressionCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
- (MDTMKotlinIntIterator *)iterator __attribute__((swift_name("iterator()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t first __attribute__((swift_name("first")));
@property (readonly) int32_t last __attribute__((swift_name("last")));
@property (readonly) int32_t step __attribute__((swift_name("step")));
@end

__attribute__((swift_name("KotlinClosedRange")))
@protocol MDTMKotlinClosedRange
@required
- (BOOL)containsValue:(id)value __attribute__((swift_name("contains(value:)")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
@property (readonly) id endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly, getter=start_) id start __attribute__((swift_name("start")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.9")
*/
__attribute__((swift_name("KotlinOpenEndRange")))
@protocol MDTMKotlinOpenEndRange
@required
- (BOOL)containsValue_:(id)value __attribute__((swift_name("contains(value_:)")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
@property (readonly) id endExclusive __attribute__((swift_name("endExclusive")));
@property (readonly, getter=start_) id start __attribute__((swift_name("start")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinIntRange")))
@interface MDTMKotlinIntRange : MDTMKotlinIntProgression <MDTMKotlinClosedRange, MDTMKotlinOpenEndRange>
- (instancetype)initWithStart:(int32_t)start endInclusive:(int32_t)endInclusive __attribute__((swift_name("init(start:endInclusive:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMKotlinIntRangeCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)containsValue:(MDTMInt *)value __attribute__((swift_name("contains(value:)")));
- (BOOL)containsValue_:(MDTMInt *)value __attribute__((swift_name("contains(value_:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.9")
*/
@property (readonly) MDTMInt *endExclusive __attribute__((swift_name("endExclusive"))) __attribute__((deprecated("Can throw an exception when it's impossible to represent the value with Int type, for example, when the range includes MAX_VALUE. It's recommended to use 'endInclusive' property that doesn't throw.")));
@property (readonly) MDTMInt *endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly, getter=start_) MDTMInt *start __attribute__((swift_name("start")));
@end

@interface MDTMKotlinIntRange (Extensions)
- (id<MDTMFlow>)asFlow __attribute__((swift_name("asFlow()")));
@end

__attribute__((swift_name("KotlinLongProgression")))
@interface MDTMKotlinLongProgression : MDTMBase <MDTMKotlinIterable>
@property (class, readonly, getter=companion) MDTMKotlinLongProgressionCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
- (MDTMKotlinLongIterator *)iterator __attribute__((swift_name("iterator()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t first __attribute__((swift_name("first")));
@property (readonly) int64_t last __attribute__((swift_name("last")));
@property (readonly) int64_t step __attribute__((swift_name("step")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinLongRange")))
@interface MDTMKotlinLongRange : MDTMKotlinLongProgression <MDTMKotlinClosedRange, MDTMKotlinOpenEndRange>
- (instancetype)initWithStart:(int64_t)start endInclusive:(int64_t)endInclusive __attribute__((swift_name("init(start:endInclusive:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMKotlinLongRangeCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)containsValue:(MDTMLong *)value __attribute__((swift_name("contains(value:)")));
- (BOOL)containsValue_:(MDTMLong *)value __attribute__((swift_name("contains(value_:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.9")
*/
@property (readonly) MDTMLong *endExclusive __attribute__((swift_name("endExclusive"))) __attribute__((deprecated("Can throw an exception when it's impossible to represent the value with Long type, for example, when the range includes MAX_VALUE. It's recommended to use 'endInclusive' property that doesn't throw.")));
@property (readonly) MDTMLong *endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly, getter=start_) MDTMLong *start __attribute__((swift_name("start")));
@end

@interface MDTMKotlinLongRange (Extensions)
- (id<MDTMFlow>)asFlow __attribute__((swift_name("asFlow()")));
@end

@interface MDTMCoroutineDispatcher (Extensions)

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeBlock:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(block:completionHandler:)")));
@end

@interface MDTMDispatchers (Extensions)
- (MDTMCoroutineDispatcher *)clientDispatcherThreadCount:(int32_t)threadCount dispatcherName:(NSString *)dispatcherName __attribute__((swift_name("clientDispatcher(threadCount:dispatcherName:)")));
@property (readonly) MDTMCoroutineDispatcher *IO __attribute__((swift_name("IO")));
@end

@interface MDTMSharingStartedCompanion (Extensions)
- (id<MDTMSharingStarted>)WhileSubscribedStopTimeout:(int64_t)stopTimeout replayExpiration:(int64_t)replayExpiration __attribute__((swift_name("WhileSubscribed(stopTimeout:replayExpiration:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AwaitKt")))
@interface MDTMAwaitKt : MDTMBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)awaitAll:(id)receiver completionHandler:(void (^)(NSArray<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("awaitAll(_:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)awaitAllDeferreds:(MDTMKotlinArray<id<MDTMDeferred>> *)deferreds completionHandler:(void (^)(NSArray<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("awaitAll(deferreds:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)joinAll:(id)receiver completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("joinAll(_:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)joinAllJobs:(MDTMKotlinArray<id<MDTMJob>> *)jobs completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("joinAll(jobs:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BodyProgressKt")))
@interface MDTMBodyProgressKt : MDTMBase
@property (class, readonly) id<MDTMClientPlugin> BodyProgress __attribute__((swift_name("BodyProgress")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BroadcastKt")))
@interface MDTMBroadcastKt : MDTMBase

/**
 * @note annotations
 *   kotlinx.coroutines.ObsoleteCoroutinesApi
*/
+ (id<MDTMBroadcastChannel>)broadcast:(id<MDTMReceiveChannel>)receiver capacity:(int32_t)capacity start:(MDTMCoroutineStart *)start __attribute__((swift_name("broadcast(_:capacity:start:)"))) __attribute__((unavailable("BroadcastChannel is deprecated in the favour of SharedFlow and is no longer supported")));

/**
 * @note annotations
 *   kotlinx.coroutines.ObsoleteCoroutinesApi
*/
+ (id<MDTMBroadcastChannel>)broadcast:(id<MDTMCoroutineScope>)receiver context:(id<MDTMKotlinCoroutineContext>)context capacity:(int32_t)capacity start:(MDTMCoroutineStart *)start onCompletion:(void (^ _Nullable)(MDTMKotlinThrowable * _Nullable))onCompletion block:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("broadcast(_:context:capacity:start:onCompletion:block:)"))) __attribute__((unavailable("BroadcastChannel is deprecated in the favour of SharedFlow and is no longer supported")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BroadcastChannelKt")))
@interface MDTMBroadcastChannelKt : MDTMBase

/**
 * @note annotations
 *   kotlinx.coroutines.ObsoleteCoroutinesApi
*/
+ (id<MDTMBroadcastChannel>)BroadcastChannelCapacity:(int32_t)capacity __attribute__((swift_name("BroadcastChannel(capacity:)"))) __attribute__((unavailable("BroadcastChannel is deprecated in the favour of SharedFlow and StateFlow, and is no longer supported")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Builders_commonKt")))
@interface MDTMBuilders_commonKt : MDTMBase
+ (id<MDTMDeferred>)async:(id<MDTMCoroutineScope>)receiver context:(id<MDTMKotlinCoroutineContext>)context start:(MDTMCoroutineStart *)start block:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("async(_:context:start:block:)")));
+ (id<MDTMJob>)launch:(id<MDTMCoroutineScope>)receiver context:(id<MDTMKotlinCoroutineContext>)context start:(MDTMCoroutineStart *)start block:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("launch(_:context:start:block:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)withContextContext:(id<MDTMKotlinCoroutineContext>)context block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("withContext(context:block:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BuildersKt")))
@interface MDTMBuildersKt : MDTMBase
+ (id<MDTMFlow>)asFlow:(id _Nullable (^)(void))receiver __attribute__((swift_name("asFlow(_:)")));
+ (id<MDTMFlow>)asFlow_:(id)receiver __attribute__((swift_name("asFlow(__:)")));
+ (id<MDTMFlow>)asFlow__:(id<MDTMKotlinIterator>)receiver __attribute__((swift_name("asFlow(___:)")));
+ (id<MDTMFlow>)asFlow___:(id<MDTMKotlinSuspendFunction0>)receiver __attribute__((swift_name("asFlow(____:)")));
+ (id<MDTMFlow>)asFlow____:(id<MDTMKotlinSequence>)receiver __attribute__((swift_name("asFlow(_____:)")));
+ (id<MDTMFlow>)callbackFlowBlock:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("callbackFlow(block:)")));
+ (id<MDTMFlow>)channelFlowBlock:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("channelFlow(block:)")));
+ (id<MDTMFlow>)emptyFlow __attribute__((swift_name("emptyFlow()")));
+ (id<MDTMFlow>)flowBlock:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("flow(block:)")));
+ (id<MDTMFlow>)flowOfValue:(id _Nullable)value __attribute__((swift_name("flowOf(value:)")));
+ (id<MDTMFlow>)flowOfElements:(MDTMKotlinArray<id> *)elements __attribute__((swift_name("flowOf(elements:)")));
+ (id _Nullable)runBlockingContext:(id<MDTMKotlinCoroutineContext>)context block:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("runBlocking(context:block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CIOKt")))
@interface MDTMCIOKt : MDTMBase
@property (class, readonly) int32_t DEFAULT_HTTP_BUFFER_SIZE __attribute__((swift_name("DEFAULT_HTTP_BUFFER_SIZE")));
@property (class, readonly) int32_t DEFAULT_HTTP_POOL_SIZE __attribute__((swift_name("DEFAULT_HTTP_POOL_SIZE")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CancellableKt")))
@interface MDTMCancellableKt : MDTMBase

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
+ (void)startCoroutineCancellable:(id<MDTMKotlinSuspendFunction0>)receiver completion:(id<MDTMKotlinContinuation>)completion __attribute__((swift_name("startCoroutineCancellable(_:completion:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CancellableContinuationKt")))
@interface MDTMCancellableContinuationKt : MDTMBase

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
+ (void)disposeOnCancellation:(id<MDTMCancellableContinuation>)receiver handle:(id<MDTMDisposableHandle>)handle __attribute__((swift_name("disposeOnCancellation(_:handle:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)suspendCancellableCoroutineBlock:(void (^)(id<MDTMCancellableContinuation>))block completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("suspendCancellableCoroutine(block:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChannelKt")))
@interface MDTMChannelKt : MDTMBase
+ (id<MDTMChannel>)ChannelCapacity:(int32_t)capacity onBufferOverflow:(MDTMBufferOverflow *)onBufferOverflow onUndeliveredElement:(void (^ _Nullable)(id _Nullable))onUndeliveredElement __attribute__((swift_name("Channel(capacity:onBufferOverflow:onUndeliveredElement:)")));
+ (id _Nullable)getOrElse:(id _Nullable)receiver onFailure:(id _Nullable (^)(MDTMKotlinThrowable * _Nullable))onFailure __attribute__((swift_name("getOrElse(_:onFailure:)")));
+ (id _Nullable)onClosed:(id _Nullable)receiver action:(void (^)(MDTMKotlinThrowable * _Nullable))action __attribute__((swift_name("onClosed(_:action:)")));
+ (id _Nullable)onFailure:(id _Nullable)receiver action:(void (^)(MDTMKotlinThrowable * _Nullable))action __attribute__((swift_name("onFailure(_:action:)")));
+ (id _Nullable)onSuccess:(id _Nullable)receiver action:(void (^)(id _Nullable))action __attribute__((swift_name("onSuccess(_:action:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Channels_commonKt")))
@interface MDTMChannels_commonKt : MDTMBase
+ (id _Nullable)consume:(id<MDTMReceiveChannel>)receiver block:(id _Nullable (^)(id<MDTMReceiveChannel>))block __attribute__((swift_name("consume(_:block:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)consumeEach:(id<MDTMReceiveChannel>)receiver action:(void (^)(id _Nullable))action completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("consumeEach(_:action:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)toList:(id<MDTMReceiveChannel>)receiver completionHandler:(void (^)(NSArray<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("toList(_:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChannelsKt")))
@interface MDTMChannelsKt : MDTMBase
+ (id<MDTMFlow>)consumeAsFlow:(id<MDTMReceiveChannel>)receiver __attribute__((swift_name("consumeAsFlow(_:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)emitAll:(id<MDTMFlowCollector>)receiver channel:(id<MDTMReceiveChannel>)channel completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emitAll(_:channel:completionHandler:)")));
+ (id<MDTMReceiveChannel>)produceIn:(id<MDTMFlow>)receiver scope:(id<MDTMCoroutineScope>)scope __attribute__((swift_name("produceIn(_:scope:)")));
+ (id<MDTMFlow>)receiveAsFlow:(id<MDTMReceiveChannel>)receiver __attribute__((swift_name("receiveAsFlow(_:)")));
+ (id _Nullable)trySendBlocking:(id<MDTMSendChannel>)receiver element:(id _Nullable)element __attribute__((swift_name("trySendBlocking(_:element:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ClientEventsKt")))
@interface MDTMClientEventsKt : MDTMBase
@property (class, readonly) MDTMKtor_eventsEventDefinition<MDTMHttpRequestBuilder *> *HttpRequestCreated __attribute__((swift_name("HttpRequestCreated")));
@property (class, readonly) MDTMKtor_eventsEventDefinition<MDTMHttpRequestBuilder *> *HttpRequestIsReadyForSending __attribute__((swift_name("HttpRequestIsReadyForSending")));
@property (class, readonly) MDTMKtor_eventsEventDefinition<MDTMHttpResponse *> *HttpResponseCancelled __attribute__((swift_name("HttpResponseCancelled")));
@property (class, readonly) MDTMKtor_eventsEventDefinition<MDTMHttpResponseReceiveFail *> *HttpResponseReceiveFailed __attribute__((swift_name("HttpResponseReceiveFailed")));
@property (class, readonly) MDTMKtor_eventsEventDefinition<MDTMHttpResponse *> *HttpResponseReceived __attribute__((swift_name("HttpResponseReceived")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ClientSSESessionKt")))
@interface MDTMClientSSESessionKt : MDTMBase
+ (id _Nullable)deserialize:(id<MDTMSSESessionWithDeserialization>)receiver event:(MDTMKtor_sseTypedServerSentEvent<NSString *> *)event __attribute__((swift_name("deserialize(_:event:)")));
+ (id _Nullable)deserialize:(id<MDTMSSESessionWithDeserialization>)receiver data:(NSString * _Nullable)data __attribute__((swift_name("deserialize(_:data:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CollectKt")))
@interface MDTMCollectKt : MDTMBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)collect:(id<MDTMFlow>)receiver completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(_:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)collectIndexed:(id<MDTMFlow>)receiver action:(id<MDTMKotlinSuspendFunction2>)action completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collectIndexed(_:action:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)collectLatest:(id<MDTMFlow>)receiver action:(id<MDTMKotlinSuspendFunction1>)action completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collectLatest(_:action:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)emitAll:(id<MDTMFlowCollector>)receiver flow:(id<MDTMFlow>)flow completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emitAll(_:flow:completionHandler:)")));
+ (id<MDTMJob>)launchIn:(id<MDTMFlow>)receiver scope:(id<MDTMCoroutineScope>)scope __attribute__((swift_name("launchIn(_:scope:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CollectionKt")))
@interface MDTMCollectionKt : MDTMBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)toCollection:(id<MDTMFlow>)receiver destination:(id)destination completionHandler:(void (^)(id _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("toCollection(_:destination:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)toList:(id<MDTMFlow>)receiver destination:(NSMutableArray<id> *)destination completionHandler:(void (^)(NSArray<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("toList(_:destination:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)toSet:(id<MDTMFlow>)receiver destination:(MDTMMutableSet<id> *)destination completionHandler:(void (^)(NSSet<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("toSet(_:destination:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CompletableDeferredKt")))
@interface MDTMCompletableDeferredKt : MDTMBase
+ (id<MDTMCompletableDeferred>)CompletableDeferredValue:(id _Nullable)value __attribute__((swift_name("CompletableDeferred(value:)")));
+ (id<MDTMCompletableDeferred>)CompletableDeferredParent:(id<MDTMJob> _Nullable)parent __attribute__((swift_name("CompletableDeferred(parent:)")));
+ (BOOL)completeWith:(id<MDTMCompletableDeferred>)receiver result:(id _Nullable)result __attribute__((swift_name("completeWith(_:result:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ContentNegotiationKt")))
@interface MDTMContentNegotiationKt : MDTMBase
@property (class, readonly) id<MDTMClientPlugin> ContentNegotiation __attribute__((swift_name("ContentNegotiation")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ContextKt")))
@interface MDTMContextKt : MDTMBase
+ (id<MDTMFlow>)buffer:(id<MDTMFlow>)receiver capacity:(int32_t)capacity onBufferOverflow:(MDTMBufferOverflow *)onBufferOverflow __attribute__((swift_name("buffer(_:capacity:onBufferOverflow:)")));
+ (id<MDTMFlow>)cancellable:(id<MDTMFlow>)receiver __attribute__((swift_name("cancellable(_:)")));
+ (id<MDTMFlow>)conflate:(id<MDTMFlow>)receiver __attribute__((swift_name("conflate(_:)")));
+ (id<MDTMFlow>)flowOn:(id<MDTMFlow>)receiver context:(id<MDTMKotlinCoroutineContext>)context __attribute__((swift_name("flowOn(_:context:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CookiesStorageKt")))
@interface MDTMCookiesStorageKt : MDTMBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)addCookie:(id<MDTMCookiesStorage>)receiver urlString:(NSString *)urlString cookie:(MDTMKtor_httpCookie *)cookie completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("addCookie(_:urlString:cookie:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoroutineContextKt")))
@interface MDTMCoroutineContextKt : MDTMBase
+ (id<MDTMKotlinCoroutineContext>)doNewCoroutineContext:(id<MDTMKotlinCoroutineContext>)receiver addedContext:(id<MDTMKotlinCoroutineContext>)addedContext __attribute__((swift_name("doNewCoroutineContext(_:addedContext:)")));
+ (id<MDTMKotlinCoroutineContext>)doNewCoroutineContext:(id<MDTMCoroutineScope>)receiver context:(id<MDTMKotlinCoroutineContext>)context __attribute__((swift_name("doNewCoroutineContext(_:context:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoroutineExceptionHandlerKt")))
@interface MDTMCoroutineExceptionHandlerKt : MDTMBase
+ (id<MDTMCoroutineExceptionHandler>)CoroutineExceptionHandlerHandler:(void (^)(id<MDTMKotlinCoroutineContext>, MDTMKotlinThrowable *))handler __attribute__((swift_name("CoroutineExceptionHandler(handler:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
+ (void)handleCoroutineExceptionContext:(id<MDTMKotlinCoroutineContext>)context exception:(MDTMKotlinThrowable *)exception __attribute__((swift_name("handleCoroutineException(context:exception:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoroutineScopeKt")))
@interface MDTMCoroutineScopeKt : MDTMBase
+ (BOOL)isActive:(id<MDTMCoroutineScope>)receiver __attribute__((swift_name("isActive(_:)")));
+ (id<MDTMCoroutineScope>)CoroutineScopeContext:(id<MDTMKotlinCoroutineContext>)context __attribute__((swift_name("CoroutineScope(context:)")));
+ (id<MDTMCoroutineScope>)MainScope __attribute__((swift_name("MainScope()")));
+ (void)cancel:(id<MDTMCoroutineScope>)receiver cause:(MDTMKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancel(_:cause:)")));
+ (void)cancel:(id<MDTMCoroutineScope>)receiver message:(NSString *)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("cancel(_:message:cause:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)coroutineScopeBlock:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("coroutineScope(block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)currentCoroutineContextWithCompletionHandler:(void (^)(id<MDTMKotlinCoroutineContext> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("currentCoroutineContext(completionHandler:)")));
+ (void)ensureActive:(id<MDTMCoroutineScope>)receiver __attribute__((swift_name("ensureActive(_:)")));
+ (id<MDTMCoroutineScope>)plus:(id<MDTMCoroutineScope>)receiver context:(id<MDTMKotlinCoroutineContext>)context __attribute__((swift_name("plus(_:context:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CountKt")))
@interface MDTMCountKt : MDTMBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)count:(id<MDTMFlow>)receiver completionHandler:(void (^)(MDTMInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("count(_:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)count:(id<MDTMFlow>)receiver predicate:(id<MDTMKotlinSuspendFunction1>)predicate completionHandler:(void (^)(MDTMInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("count(_:predicate:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CreatePluginUtilsKt")))
@interface MDTMCreatePluginUtilsKt : MDTMBase
+ (id<MDTMClientPlugin>)createClientPluginName:(NSString *)name body:(void (^)(MDTMClientPluginBuilder<MDTMKotlinUnit *> *))body __attribute__((swift_name("createClientPlugin(name:body:)")));
+ (id<MDTMClientPlugin>)createClientPluginName:(NSString *)name createConfiguration:(id (^)(void))createConfiguration body:(void (^)(MDTMClientPluginBuilder<id> *))body __attribute__((swift_name("createClientPlugin(name:createConfiguration:body:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DelayKt")))
@interface MDTMDelayKt : MDTMBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)awaitCancellationWithCompletionHandler:(void (^)(MDTMKotlinNothing * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("awaitCancellation(completionHandler:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.FlowPreview
*/
+ (id<MDTMFlow>)debounce:(id<MDTMFlow>)receiver timeoutMillis:(MDTMLong *(^)(id _Nullable))timeoutMillis __attribute__((swift_name("debounce(_:timeoutMillis:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.FlowPreview
 *   kotlin.jvm.JvmName(name="debounceDuration")
*/
+ (id<MDTMFlow>)debounce:(id<MDTMFlow>)receiver timeout:(id (^)(id _Nullable))timeout __attribute__((swift_name("debounce(_:timeout:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.FlowPreview
*/
+ (id<MDTMFlow>)debounce:(id<MDTMFlow>)receiver timeoutMillis_:(int64_t)timeoutMillis __attribute__((swift_name("debounce(_:timeoutMillis_:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.FlowPreview
*/
+ (id<MDTMFlow>)debounce:(id<MDTMFlow>)receiver timeout_:(int64_t)timeout __attribute__((swift_name("debounce(_:timeout_:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)delayTimeMillis:(int64_t)timeMillis completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("delay(timeMillis:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)delayDuration:(int64_t)duration completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("delay(duration:completionHandler:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.FlowPreview
*/
+ (id<MDTMFlow>)sample:(id<MDTMFlow>)receiver periodMillis:(int64_t)periodMillis __attribute__((swift_name("sample(_:periodMillis:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.FlowPreview
*/
+ (id<MDTMFlow>)sample:(id<MDTMFlow>)receiver period:(int64_t)period __attribute__((swift_name("sample(_:period:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.FlowPreview
*/
+ (id<MDTMFlow>)timeout:(id<MDTMFlow>)receiver timeout:(int64_t)timeout __attribute__((swift_name("timeout(_:timeout:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeprecatedKt")))
@interface MDTMDeprecatedKt : MDTMBase

/**
 * @note annotations
 *   kotlinx.coroutines.ObsoleteCoroutinesApi
*/
+ (id _Nullable)consume:(id<MDTMBroadcastChannel>)receiver block:(id _Nullable (^)(id<MDTMReceiveChannel>))block __attribute__((swift_name("consume(_:block:)"))) __attribute__((unavailable("BroadcastChannel is deprecated in the favour of SharedFlow and is no longer supported")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)consumeEach:(id<MDTMBroadcastChannel>)receiver action:(void (^)(id _Nullable))action completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("consumeEach(_:action:completionHandler:)"))) __attribute__((unavailable("BroadcastChannel is deprecated in the favour of SharedFlow and is no longer supported")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DispatchedContinuationKt")))
@interface MDTMDispatchedContinuationKt : MDTMBase

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
+ (void)resumeCancellableWith:(id<MDTMKotlinContinuation>)receiver result:(id _Nullable)result __attribute__((swift_name("resumeCancellableWith(_:result:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DistinctKt")))
@interface MDTMDistinctKt : MDTMBase
+ (id<MDTMFlow>)distinctUntilChanged:(id<MDTMFlow>)receiver __attribute__((swift_name("distinctUntilChanged(_:)")));
+ (id<MDTMFlow>)distinctUntilChanged:(id<MDTMFlow>)receiver areEquivalent:(MDTMBoolean *(^)(id _Nullable, id _Nullable))areEquivalent __attribute__((swift_name("distinctUntilChanged(_:areEquivalent:)")));
+ (id<MDTMFlow>)distinctUntilChangedBy:(id<MDTMFlow>)receiver keySelector:(id _Nullable (^)(id _Nullable))keySelector __attribute__((swift_name("distinctUntilChangedBy(_:keySelector:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DurationsKt")))
@interface MDTMDurationsKt : MDTMBase
+ (MDTMWebSockets *)WebSocketsPingInterval:(id _Nullable)pingInterval maxFrameSize:(int64_t)maxFrameSize __attribute__((swift_name("WebSockets(pingInterval:maxFrameSize:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EmittersKt")))
@interface MDTMEmittersKt : MDTMBase
+ (id<MDTMFlow>)onCompletion:(id<MDTMFlow>)receiver action:(id<MDTMKotlinSuspendFunction2>)action __attribute__((swift_name("onCompletion(_:action:)")));
+ (id<MDTMFlow>)onEmpty:(id<MDTMFlow>)receiver action:(id<MDTMKotlinSuspendFunction1>)action __attribute__((swift_name("onEmpty(_:action:)")));
+ (id<MDTMFlow>)onStart:(id<MDTMFlow>)receiver action:(id<MDTMKotlinSuspendFunction1>)action __attribute__((swift_name("onStart(_:action:)")));
+ (id<MDTMFlow>)transform:(id<MDTMFlow>)receiver transform:(id<MDTMKotlinSuspendFunction2>)transform __attribute__((swift_name("transform(_:transform:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ErrorsKt")))
@interface MDTMErrorsKt : MDTMBase
+ (id<MDTMFlow>)catch:(id<MDTMFlow>)receiver action:(id<MDTMKotlinSuspendFunction2>)action __attribute__((swift_name("catch(_:action:)")));
+ (id<MDTMFlow>)retry:(id<MDTMFlow>)receiver retries:(int64_t)retries predicate:(id<MDTMKotlinSuspendFunction1>)predicate __attribute__((swift_name("retry(_:retries:predicate:)")));
+ (id<MDTMFlow>)retryWhen:(id<MDTMFlow>)receiver predicate:(id<MDTMKotlinSuspendFunction3>)predicate __attribute__((swift_name("retryWhen(_:predicate:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ExceptionsKt")))
@interface MDTMExceptionsKt : MDTMBase
+ (MDTMKotlinCancellationException *)CancellationExceptionMessage:(NSString * _Nullable)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("CancellationException(message:cause:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GuidanceKt")))
@interface MDTMGuidanceKt : MDTMBase
+ (id<MDTMDeferred>)asyncContext:(id<MDTMKotlinCoroutineContext>)context start:(MDTMCoroutineStart *)start block:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("async(context:start:block:)"))) __attribute__((unavailable("'async' can not be called without the corresponding coroutine scope. Consider wrapping 'async' in 'coroutineScope { }', using 'runBlocking { }', or using some other 'CoroutineScope'")));
+ (id<MDTMJob>)launchContext:(id<MDTMKotlinCoroutineContext>)context start:(MDTMCoroutineStart *)start block:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("launch(context:start:block:)"))) __attribute__((unavailable("'launch' can not be called without the corresponding coroutine scope. Consider wrapping 'launch' in 'coroutineScope { }', using 'runBlocking { }', or using some other 'CoroutineScope'")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpCacheStorageKt")))
@interface MDTMHttpCacheStorageKt : MDTMBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)store:(id<MDTMCacheStorage>)receiver response:(MDTMHttpResponse *)response completionHandler:(void (^)(MDTMCachedResponseData * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("store(_:response:completionHandler:)"))) __attribute__((unavailable("Please use method with `response.varyKeys()` and `isShared` arguments")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)store:(id<MDTMCacheStorage>)receiver response:(MDTMHttpResponse *)response varyKeys:(NSDictionary<NSString *, NSString *> *)varyKeys isShared:(BOOL)isShared completionHandler:(void (^)(MDTMCachedResponseData * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("store(_:response:varyKeys:isShared:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpCallValidatorKt")))
@interface MDTMHttpCallValidatorKt : MDTMBase
@property (class, readonly) id<MDTMClientPlugin> HttpCallValidator __attribute__((swift_name("HttpCallValidator")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpClientKt")))
@interface MDTMHttpClientKt : MDTMBase
+ (MDTMHttpClient *)HttpClientBlock:(void (^)(MDTMHttpClientConfig<id> *))block __attribute__((swift_name("HttpClient(block:)")));
+ (MDTMHttpClient *)HttpClientEngine:(id<MDTMHttpClientEngine>)engine block:(void (^)(MDTMHttpClientConfig<id> *))block __attribute__((swift_name("HttpClient(engine:block:)")));
+ (MDTMHttpClient *)HttpClientEngineFactory:(id<MDTMHttpClientEngineFactory>)engineFactory block:(void (^)(MDTMHttpClientConfig<MDTMHttpClientEngineConfig *> *))block __attribute__((swift_name("HttpClient(engineFactory:block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpClientEngineKt")))
@interface MDTMHttpClientEngineKt : MDTMBase
+ (id<MDTMHttpClientEngineFactory>)config:(id<MDTMHttpClientEngineFactory>)receiver nested:(void (^)(MDTMHttpClientEngineConfig *))nested __attribute__((swift_name("config(_:nested:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpClientEngineCapabilityKt")))
@interface MDTMHttpClientEngineCapabilityKt : MDTMBase
@property (class, readonly) NSSet<id<MDTMHttpClientEngineCapability>> *DEFAULT_CAPABILITIES __attribute__((swift_name("DEFAULT_CAPABILITIES")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpCookiesKt")))
@interface MDTMHttpCookiesKt : MDTMBase
+ (MDTMKtor_httpCookie * _Nullable)get:(NSArray<MDTMKtor_httpCookie *> *)receiver name:(NSString *)name __attribute__((swift_name("get(_:name:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpEngineFactoryKt")))
@interface MDTMHttpEngineFactoryKt : MDTMBase
@property (class, readonly) NSString *TAG __attribute__((swift_name("TAG")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpPlainTextKt")))
@interface MDTMHttpPlainTextKt : MDTMBase
@property (class, readonly) id<MDTMClientPlugin> HttpPlainText __attribute__((swift_name("HttpPlainText")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRedirectKt")))
@interface MDTMHttpRedirectKt : MDTMBase
@property (class, readonly) id<MDTMClientPlugin> HttpRedirect __attribute__((swift_name("HttpRedirect")));
@property (class, readonly) MDTMKtor_eventsEventDefinition<MDTMHttpResponse *> *HttpResponseRedirectEvent __attribute__((swift_name("HttpResponseRedirectEvent")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRequestKt")))
@interface MDTMHttpRequestKt : MDTMBase
+ (MDTMKtor_httpHeadersBuilder *)headers:(id<MDTMKtor_httpHttpMessageBuilder>)receiver block:(void (^)(MDTMKtor_httpHeadersBuilder *))block __attribute__((swift_name("headers(_:block:)")));
@property (class, readonly) MDTMKtor_utilsAttributeKey<id<MDTMResponseAdapter>> *ResponseAdapterAttributeKey __attribute__((swift_name("ResponseAdapterAttributeKey")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRequestLifecycleKt")))
@interface MDTMHttpRequestLifecycleKt : MDTMBase
@property (class, readonly) id<MDTMClientPlugin> HttpRequestLifecycle __attribute__((swift_name("HttpRequestLifecycle")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpRequestRetryKt")))
@interface MDTMHttpRequestRetryKt : MDTMBase
@property (class, readonly) id<MDTMClientPlugin> HttpRequestRetry __attribute__((swift_name("HttpRequestRetry")));
@property (class, readonly) MDTMKtor_eventsEventDefinition<MDTMHttpRetryEventData *> *HttpRequestRetryEvent __attribute__((swift_name("HttpRequestRetryEvent")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpTimeoutKt")))
@interface MDTMHttpTimeoutKt : MDTMBase
+ (MDTMConnectTimeoutException *)ConnectTimeoutExceptionRequest:(MDTMHttpRequestData *)request cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("ConnectTimeoutException(request:cause:)")));
+ (MDTMConnectTimeoutException *)ConnectTimeoutExceptionUrl:(NSString *)url timeout:(MDTMLong * _Nullable)timeout cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("ConnectTimeoutException(url:timeout:cause:)")));
+ (MDTMSocketTimeoutException *)SocketTimeoutExceptionRequest:(MDTMHttpRequestData *)request cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("SocketTimeoutException(request:cause:)")));
+ (int32_t)convertLongTimeoutToIntWithInfiniteAsZeroTimeout:(int64_t)timeout __attribute__((swift_name("convertLongTimeoutToIntWithInfiniteAsZero(timeout:)")));
+ (int64_t)convertLongTimeoutToLongWithInfiniteAsZeroTimeout:(int64_t)timeout __attribute__((swift_name("convertLongTimeoutToLongWithInfiniteAsZero(timeout:)")));
@property (class, readonly) id<MDTMClientPlugin> HttpTimeout __attribute__((swift_name("HttpTimeout")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("JobKt")))
@interface MDTMJobKt : MDTMBase
+ (BOOL)isActive:(id<MDTMKotlinCoroutineContext>)receiver __attribute__((swift_name("isActive(_:)")));
+ (id<MDTMJob>)job:(id<MDTMKotlinCoroutineContext>)receiver __attribute__((swift_name("job(_:)")));
+ (id<MDTMCompletableJob>)JobParent:(id<MDTMJob> _Nullable)parent __attribute__((swift_name("Job(parent:)")));
+ (void)cancel:(id<MDTMKotlinCoroutineContext>)receiver cause:(MDTMKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancel(_:cause:)")));
+ (void)cancel:(id<MDTMJob>)receiver message:(NSString *)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("cancel(_:message:cause:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)cancelAndJoin:(id<MDTMJob>)receiver completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("cancelAndJoin(_:completionHandler:)")));
+ (void)cancelChildren:(id<MDTMKotlinCoroutineContext>)receiver cause:(MDTMKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancelChildren(_:cause:)")));
+ (void)cancelChildren:(id<MDTMJob>)receiver cause_:(MDTMKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancelChildren(_:cause_:)")));
+ (void)ensureActive:(id<MDTMKotlinCoroutineContext>)receiver __attribute__((swift_name("ensureActive(_:)")));
+ (void)ensureActive_:(id<MDTMJob>)receiver __attribute__((swift_name("ensureActive(__:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LimitKt")))
@interface MDTMLimitKt : MDTMBase
+ (id<MDTMFlow>)drop:(id<MDTMFlow>)receiver count:(int32_t)count __attribute__((swift_name("drop(_:count:)")));
+ (id<MDTMFlow>)dropWhile:(id<MDTMFlow>)receiver predicate:(id<MDTMKotlinSuspendFunction1>)predicate __attribute__((swift_name("dropWhile(_:predicate:)")));
+ (id<MDTMFlow>)take:(id<MDTMFlow>)receiver count:(int32_t)count __attribute__((swift_name("take(_:count:)")));
+ (id<MDTMFlow>)takeWhile:(id<MDTMFlow>)receiver predicate:(id<MDTMKotlinSuspendFunction1>)predicate __attribute__((swift_name("takeWhile(_:predicate:)")));
+ (id<MDTMFlow>)transformWhile:(id<MDTMFlow>)receiver transform:(id<MDTMKotlinSuspendFunction2>)transform __attribute__((swift_name("transformWhile(_:transform:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LintKt")))
@interface MDTMLintKt : MDTMBase
+ (id<MDTMKotlinCoroutineContext>)coroutineContext:(id<MDTMFlowCollector>)receiver __attribute__((swift_name("coroutineContext(_:)"))) __attribute__((unavailable("coroutineContext is resolved into the property of outer CoroutineScope which is likely to be an error. Use currentCoroutineContext() instead or specify the receiver of coroutineContext explicitly")));
+ (BOOL)isActive:(id<MDTMFlowCollector>)receiver __attribute__((swift_name("isActive(_:)"))) __attribute__((unavailable("isActive is resolved into the extension of outer CoroutineScope which is likely to be an error. Use currentCoroutineContext().isActive or cancellable() operator instead or specify the receiver of isActive explicitly. Additionally, flow {} builder emissions are cancellable by default.")));
+ (void)cancel:(id<MDTMFlowCollector>)receiver cause:(MDTMKotlinCancellationException * _Nullable)cause __attribute__((swift_name("cancel(_:cause:)"))) __attribute__((unavailable("cancel() is resolved into the extension of outer CoroutineScope which is likely to be an error. Use currentCoroutineContext().cancel() instead or specify the receiver of cancel() explicitly")));
+ (id<MDTMFlow>)cancellable:(id<MDTMSharedFlow>)receiver __attribute__((swift_name("cancellable(_:)"))) __attribute__((unavailable("Applying 'cancellable' to a SharedFlow has no effect. See the SharedFlow documentation on Operator Fusion.")));
+ (id<MDTMFlow>)catch:(id<MDTMSharedFlow>)receiver action:(id<MDTMKotlinSuspendFunction2>)action __attribute__((swift_name("catch(_:action:)"))) __attribute__((deprecated("SharedFlow never completes, so this operator typically has not effect, it can only catch exceptions from 'onSubscribe' operator")));
+ (id<MDTMFlow>)conflate:(id<MDTMStateFlow>)receiver __attribute__((swift_name("conflate(_:)"))) __attribute__((unavailable("Applying 'conflate' to StateFlow has no effect. See the StateFlow documentation on Operator Fusion.")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)count:(id<MDTMSharedFlow>)receiver completionHandler:(void (^)(MDTMInt * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("count(_:completionHandler:)"))) __attribute__((deprecated("SharedFlow never completes, so this terminal operation never completes.")));
+ (id<MDTMFlow>)distinctUntilChanged:(id<MDTMStateFlow>)receiver __attribute__((swift_name("distinctUntilChanged(_:)"))) __attribute__((unavailable("Applying 'distinctUntilChanged' to StateFlow has no effect. See the StateFlow documentation on Operator Fusion.")));
+ (id<MDTMFlow>)flowOn:(id<MDTMSharedFlow>)receiver context:(id<MDTMKotlinCoroutineContext>)context __attribute__((swift_name("flowOn(_:context:)"))) __attribute__((unavailable("Applying 'flowOn' to SharedFlow has no effect. See the SharedFlow documentation on Operator Fusion.")));
+ (id<MDTMFlow>)retry:(id<MDTMSharedFlow>)receiver retries:(int64_t)retries predicate:(id<MDTMKotlinSuspendFunction1>)predicate __attribute__((swift_name("retry(_:retries:predicate:)"))) __attribute__((deprecated("SharedFlow never completes, so this operator has no effect.")));
+ (id<MDTMFlow>)retryWhen:(id<MDTMSharedFlow>)receiver predicate:(id<MDTMKotlinSuspendFunction3>)predicate __attribute__((swift_name("retryWhen(_:predicate:)"))) __attribute__((deprecated("SharedFlow never completes, so this operator has no effect.")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)toList:(id<MDTMSharedFlow>)receiver completionHandler:(void (^)(NSArray<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("toList(_:completionHandler:)"))) __attribute__((deprecated("SharedFlow never completes, so this terminal operation never completes.")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)toList:(id<MDTMSharedFlow>)receiver destination:(NSMutableArray<id> *)destination completionHandler:(void (^)(MDTMKotlinNothing * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("toList(_:destination:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)toSet:(id<MDTMSharedFlow>)receiver completionHandler:(void (^)(NSSet<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("toSet(_:completionHandler:)"))) __attribute__((deprecated("SharedFlow never completes, so this terminal operation never completes.")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)toSet:(id<MDTMSharedFlow>)receiver destination:(MDTMMutableSet<id> *)destination completionHandler:(void (^)(MDTMKotlinNothing * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("toSet(_:destination:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LogicKt")))
@interface MDTMLogicKt : MDTMBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)all:(id<MDTMFlow>)receiver predicate:(id<MDTMKotlinSuspendFunction1>)predicate completionHandler:(void (^)(MDTMBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("all(_:predicate:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)any:(id<MDTMFlow>)receiver predicate:(id<MDTMKotlinSuspendFunction1>)predicate completionHandler:(void (^)(MDTMBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("any(_:predicate:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)none:(id<MDTMFlow>)receiver predicate:(id<MDTMKotlinSuspendFunction1>)predicate completionHandler:(void (^)(MDTMBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("none(_:predicate:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MergeKt")))
@interface MDTMMergeKt : MDTMBase

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
+ (id<MDTMFlow>)flatMapConcat:(id<MDTMFlow>)receiver transform:(id<MDTMKotlinSuspendFunction1>)transform __attribute__((swift_name("flatMapConcat(_:transform:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
+ (id<MDTMFlow>)flatMapLatest:(id<MDTMFlow>)receiver transform:(id<MDTMKotlinSuspendFunction1>)transform __attribute__((swift_name("flatMapLatest(_:transform:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
+ (id<MDTMFlow>)flatMapMerge:(id<MDTMFlow>)receiver concurrency:(int32_t)concurrency transform:(id<MDTMKotlinSuspendFunction1>)transform __attribute__((swift_name("flatMapMerge(_:concurrency:transform:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
+ (id<MDTMFlow>)flattenConcat:(id<MDTMFlow>)receiver __attribute__((swift_name("flattenConcat(_:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
+ (id<MDTMFlow>)flattenMerge:(id<MDTMFlow>)receiver concurrency:(int32_t)concurrency __attribute__((swift_name("flattenMerge(_:concurrency:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
+ (id<MDTMFlow>)mapLatest:(id<MDTMFlow>)receiver transform:(id<MDTMKotlinSuspendFunction1>)transform __attribute__((swift_name("mapLatest(_:transform:)")));
+ (id<MDTMFlow>)merge:(id)receiver __attribute__((swift_name("merge(_:)")));
+ (id<MDTMFlow>)mergeFlows:(MDTMKotlinArray<id<MDTMFlow>> *)flows __attribute__((swift_name("merge(flows:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
+ (id<MDTMFlow>)transformLatest:(id<MDTMFlow>)receiver transform:(id<MDTMKotlinSuspendFunction2>)transform __attribute__((swift_name("transformLatest(_:transform:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.FlowPreview
*/
@property (class, readonly) int32_t DEFAULT_CONCURRENCY __attribute__((swift_name("DEFAULT_CONCURRENCY")));

/**
 * @note annotations
 *   kotlinx.coroutines.FlowPreview
*/
@property (class, readonly) NSString *DEFAULT_CONCURRENCY_PROPERTY_NAME __attribute__((swift_name("DEFAULT_CONCURRENCY_PROPERTY_NAME")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MigrationKt")))
@interface MDTMMigrationKt : MDTMBase
+ (id<MDTMFlow>)cache:(id<MDTMFlow>)receiver __attribute__((swift_name("cache(_:)"))) __attribute__((unavailable("Flow analogue of 'cache()' is 'shareIn' with unlimited replay and 'started = SharingStarted.Lazily' argument'")));
+ (id<MDTMFlow>)combineLatest:(id<MDTMFlow>)receiver other:(id<MDTMFlow>)other transform:(id<MDTMKotlinSuspendFunction2>)transform __attribute__((swift_name("combineLatest(_:other:transform:)"))) __attribute__((unavailable("Flow analogue of 'combineLatest' is 'combine'")));
+ (id<MDTMFlow>)combineLatest:(id<MDTMFlow>)receiver other:(id<MDTMFlow>)other other2:(id<MDTMFlow>)other2 transform:(id<MDTMKotlinSuspendFunction3>)transform __attribute__((swift_name("combineLatest(_:other:other2:transform:)"))) __attribute__((unavailable("Flow analogue of 'combineLatest' is 'combine'")));
+ (id<MDTMFlow>)combineLatest:(id<MDTMFlow>)receiver other:(id<MDTMFlow>)other other2:(id<MDTMFlow>)other2 other3:(id<MDTMFlow>)other3 transform:(id<MDTMKotlinSuspendFunction4>)transform __attribute__((swift_name("combineLatest(_:other:other2:other3:transform:)"))) __attribute__((unavailable("Flow analogue of 'combineLatest' is 'combine'")));
+ (id<MDTMFlow>)combineLatest:(id<MDTMFlow>)receiver other:(id<MDTMFlow>)other other2:(id<MDTMFlow>)other2 other3:(id<MDTMFlow>)other3 other4:(id<MDTMFlow>)other4 transform:(id<MDTMKotlinSuspendFunction5>)transform __attribute__((swift_name("combineLatest(_:other:other2:other3:other4:transform:)"))) __attribute__((unavailable("Flow analogue of 'combineLatest' is 'combine'")));
+ (id<MDTMFlow>)compose:(id<MDTMFlow>)receiver transformer:(id<MDTMFlow> (^)(id<MDTMFlow>))transformer __attribute__((swift_name("compose(_:transformer:)"))) __attribute__((unavailable("Flow analogue of 'compose' is 'let'")));
+ (id<MDTMFlow>)concatMap:(id<MDTMFlow>)receiver mapper:(id<MDTMFlow> (^)(id _Nullable))mapper __attribute__((swift_name("concatMap(_:mapper:)"))) __attribute__((unavailable("Flow analogue of 'concatMap' is 'flatMapConcat'")));
+ (id<MDTMFlow>)concatWith:(id<MDTMFlow>)receiver value:(id _Nullable)value __attribute__((swift_name("concatWith(_:value:)"))) __attribute__((unavailable("Flow analogue of 'concatWith' is 'onCompletion'. Use 'onCompletion { emit(value) }'")));
+ (id<MDTMFlow>)concatWith:(id<MDTMFlow>)receiver other:(id<MDTMFlow>)other __attribute__((swift_name("concatWith(_:other:)"))) __attribute__((unavailable("Flow analogue of 'concatWith' is 'onCompletion'. Use 'onCompletion { if (it == null) emitAll(other) }'")));
+ (id<MDTMFlow>)delayEach:(id<MDTMFlow>)receiver timeMillis:(int64_t)timeMillis __attribute__((swift_name("delayEach(_:timeMillis:)"))) __attribute__((unavailable("Use 'onEach { delay(timeMillis) }'")));
+ (id<MDTMFlow>)delayFlow:(id<MDTMFlow>)receiver timeMillis:(int64_t)timeMillis __attribute__((swift_name("delayFlow(_:timeMillis:)"))) __attribute__((unavailable("Use 'onStart { delay(timeMillis) }'")));
+ (id<MDTMFlow>)flatMap:(id<MDTMFlow>)receiver mapper:(id<MDTMKotlinSuspendFunction1>)mapper __attribute__((swift_name("flatMap(_:mapper:)"))) __attribute__((unavailable("Flow analogue is 'flatMapConcat'")));
+ (id<MDTMFlow>)flatten:(id<MDTMFlow>)receiver __attribute__((swift_name("flatten(_:)"))) __attribute__((unavailable("Flow analogue of 'flatten' is 'flattenConcat'")));
+ (void)forEach:(id<MDTMFlow>)receiver action:(id<MDTMKotlinSuspendFunction1>)action __attribute__((swift_name("forEach(_:action:)"))) __attribute__((unavailable("Flow analogue of 'forEach' is 'collect'")));
+ (id<MDTMFlow>)merge:(id<MDTMFlow>)receiver __attribute__((swift_name("merge(_:)"))) __attribute__((unavailable("Flow analogue of 'merge' is 'flattenConcat'")));
+ (id<MDTMFlow>)observeOn:(id<MDTMFlow>)receiver context:(id<MDTMKotlinCoroutineContext>)context __attribute__((swift_name("observeOn(_:context:)"))) __attribute__((unavailable("Collect flow in the desired context instead")));
+ (id<MDTMFlow>)onErrorResume:(id<MDTMFlow>)receiver fallback:(id<MDTMFlow>)fallback __attribute__((swift_name("onErrorResume(_:fallback:)"))) __attribute__((unavailable("Flow analogue of 'onErrorXxx' is 'catch'. Use 'catch { emitAll(fallback) }'")));
+ (id<MDTMFlow>)onErrorResumeNext:(id<MDTMFlow>)receiver fallback:(id<MDTMFlow>)fallback __attribute__((swift_name("onErrorResumeNext(_:fallback:)"))) __attribute__((unavailable("Flow analogue of 'onErrorXxx' is 'catch'. Use 'catch { emitAll(fallback) }'")));
+ (id<MDTMFlow>)onErrorReturn:(id<MDTMFlow>)receiver fallback:(id _Nullable)fallback __attribute__((swift_name("onErrorReturn(_:fallback:)"))) __attribute__((unavailable("Flow analogue of 'onErrorXxx' is 'catch'. Use 'catch { emit(fallback) }'")));
+ (id<MDTMFlow>)onErrorReturn:(id<MDTMFlow>)receiver fallback:(id _Nullable)fallback predicate:(MDTMBoolean *(^)(MDTMKotlinThrowable *))predicate __attribute__((swift_name("onErrorReturn(_:fallback:predicate:)"))) __attribute__((unavailable("Flow analogue of 'onErrorXxx' is 'catch'. Use 'catch { e -> if (predicate(e)) emit(fallback) else throw e }'")));
+ (id<MDTMFlow>)publish:(id<MDTMFlow>)receiver __attribute__((swift_name("publish(_:)"))) __attribute__((unavailable("Flow analogue of 'publish()' is 'shareIn'. \npublish().connect() is the default strategy (no extra call is needed), \npublish().autoConnect() translates to 'started = SharingStarted.Lazily' argument, \npublish().refCount() translates to 'started = SharingStarted.WhileSubscribed()' argument.")));
+ (id<MDTMFlow>)publish:(id<MDTMFlow>)receiver bufferSize:(int32_t)bufferSize __attribute__((swift_name("publish(_:bufferSize:)"))) __attribute__((unavailable("Flow analogue of 'publish(bufferSize)' is 'buffer' followed by 'shareIn'. \npublish().connect() is the default strategy (no extra call is needed), \npublish().autoConnect() translates to 'started = SharingStarted.Lazily' argument, \npublish().refCount() translates to 'started = SharingStarted.WhileSubscribed()' argument.")));
+ (id<MDTMFlow>)publishOn:(id<MDTMFlow>)receiver context:(id<MDTMKotlinCoroutineContext>)context __attribute__((swift_name("publishOn(_:context:)"))) __attribute__((unavailable("Collect flow in the desired context instead")));
+ (id<MDTMFlow>)replay:(id<MDTMFlow>)receiver __attribute__((swift_name("replay(_:)"))) __attribute__((unavailable("Flow analogue of 'replay()' is 'shareIn' with unlimited replay. \nreplay().connect() is the default strategy (no extra call is needed), \nreplay().autoConnect() translates to 'started = SharingStarted.Lazily' argument, \nreplay().refCount() translates to 'started = SharingStarted.WhileSubscribed()' argument.")));
+ (id<MDTMFlow>)replay:(id<MDTMFlow>)receiver bufferSize:(int32_t)bufferSize __attribute__((swift_name("replay(_:bufferSize:)"))) __attribute__((unavailable("Flow analogue of 'replay(bufferSize)' is 'shareIn' with the specified replay parameter. \nreplay().connect() is the default strategy (no extra call is needed), \nreplay().autoConnect() translates to 'started = SharingStarted.Lazily' argument, \nreplay().refCount() translates to 'started = SharingStarted.WhileSubscribed()' argument.")));
+ (id<MDTMFlow>)scanFold:(id<MDTMFlow>)receiver initial:(id _Nullable)initial operation:(id<MDTMKotlinSuspendFunction2>)operation __attribute__((swift_name("scanFold(_:initial:operation:)"))) __attribute__((unavailable("Flow has less verbose 'scan' shortcut")));
+ (id<MDTMFlow>)scanReduce:(id<MDTMFlow>)receiver operation:(id<MDTMKotlinSuspendFunction2>)operation __attribute__((swift_name("scanReduce(_:operation:)"))) __attribute__((unavailable("'scanReduce' was renamed to 'runningReduce' to be consistent with Kotlin standard library")));
+ (id<MDTMFlow>)skip:(id<MDTMFlow>)receiver count:(int32_t)count __attribute__((swift_name("skip(_:count:)"))) __attribute__((unavailable("Flow analogue of 'skip' is 'drop'")));
+ (id<MDTMFlow>)startWith:(id<MDTMFlow>)receiver value:(id _Nullable)value __attribute__((swift_name("startWith(_:value:)"))) __attribute__((unavailable("Flow analogue of 'startWith' is 'onStart'. Use 'onStart { emit(value) }'")));
+ (id<MDTMFlow>)startWith:(id<MDTMFlow>)receiver other:(id<MDTMFlow>)other __attribute__((swift_name("startWith(_:other:)"))) __attribute__((unavailable("Flow analogue of 'startWith' is 'onStart'. Use 'onStart { emitAll(other) }'")));
+ (void)subscribe:(id<MDTMFlow>)receiver __attribute__((swift_name("subscribe(_:)"))) __attribute__((unavailable("Use 'launchIn' with 'onEach', 'onCompletion' and 'catch' instead")));
+ (void)subscribe:(id<MDTMFlow>)receiver onEach:(id<MDTMKotlinSuspendFunction1>)onEach __attribute__((swift_name("subscribe(_:onEach:)"))) __attribute__((unavailable("Use 'launchIn' with 'onEach', 'onCompletion' and 'catch' instead")));
+ (void)subscribe:(id<MDTMFlow>)receiver onEach:(id<MDTMKotlinSuspendFunction1>)onEach onError:(id<MDTMKotlinSuspendFunction1>)onError __attribute__((swift_name("subscribe(_:onEach:onError:)"))) __attribute__((unavailable("Use 'launchIn' with 'onEach', 'onCompletion' and 'catch' instead")));
+ (id<MDTMFlow>)subscribeOn:(id<MDTMFlow>)receiver context:(id<MDTMKotlinCoroutineContext>)context __attribute__((swift_name("subscribeOn(_:context:)"))) __attribute__((unavailable("Use 'flowOn' instead")));
+ (id<MDTMFlow>)switchMap:(id<MDTMFlow>)receiver transform:(id<MDTMKotlinSuspendFunction1>)transform __attribute__((swift_name("switchMap(_:transform:)"))) __attribute__((unavailable("Flow analogues of 'switchMap' are 'transformLatest', 'flatMapLatest' and 'mapLatest'")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MultithreadedDispatchers_commonKt")))
@interface MDTMMultithreadedDispatchers_commonKt : MDTMBase

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
 *   kotlinx.coroutines.DelicateCoroutinesApi
*/
+ (MDTMCloseableCoroutineDispatcher *)doNewSingleThreadContextName:(NSString *)name __attribute__((swift_name("doNewSingleThreadContext(name:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MultithreadedDispatchersKt")))
@interface MDTMMultithreadedDispatchersKt : MDTMBase

/**
 * @note annotations
 *   kotlinx.coroutines.DelicateCoroutinesApi
*/
+ (MDTMCloseableCoroutineDispatcher *)doNewFixedThreadPoolContextNThreads:(int32_t)nThreads name:(NSString *)name __attribute__((swift_name("doNewFixedThreadPoolContext(nThreads:name:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MutexKt")))
@interface MDTMMutexKt : MDTMBase
+ (id<MDTMMutex>)MutexLocked:(BOOL)locked __attribute__((swift_name("Mutex(locked:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)withLock:(id<MDTMMutex>)receiver owner:(id _Nullable)owner action:(id _Nullable (^)(void))action completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("withLock(_:owner:action:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OnTimeoutKt")))
@interface MDTMOnTimeoutKt : MDTMBase

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
+ (void)onTimeout:(id<MDTMSelectBuilder>)receiver timeMillis:(int64_t)timeMillis block:(id<MDTMKotlinSuspendFunction0>)block __attribute__((swift_name("onTimeout(_:timeMillis:block:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
+ (void)onTimeout:(id<MDTMSelectBuilder>)receiver timeout:(int64_t)timeout block:(id<MDTMKotlinSuspendFunction0>)block __attribute__((swift_name("onTimeout(_:timeout:block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Platform_iosKt")))
@interface MDTMPlatform_iosKt : MDTMBase
+ (id<MDTMPlatform>)getPlatform __attribute__((swift_name("getPlatform()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProduceKt")))
@interface MDTMProduceKt : MDTMBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)awaitClose:(id<MDTMProducerScope>)receiver block:(void (^)(void))block completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("awaitClose(_:block:completionHandler:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
+ (id<MDTMReceiveChannel>)produce:(id<MDTMCoroutineScope>)receiver context:(id<MDTMKotlinCoroutineContext>)context capacity:(int32_t)capacity block:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("produce(_:context:capacity:block:)")));

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
+ (id<MDTMReceiveChannel>)produce:(id<MDTMCoroutineScope>)receiver context:(id<MDTMKotlinCoroutineContext>)context capacity:(int32_t)capacity start:(MDTMCoroutineStart *)start onCompletion:(void (^ _Nullable)(MDTMKotlinThrowable * _Nullable))onCompletion block:(id<MDTMKotlinSuspendFunction1>)block __attribute__((swift_name("produce(_:context:capacity:start:onCompletion:block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ReduceKt")))
@interface MDTMReduceKt : MDTMBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)first:(id<MDTMFlow>)receiver completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("first(_:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)first:(id<MDTMFlow>)receiver predicate:(id<MDTMKotlinSuspendFunction1>)predicate completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("first(_:predicate:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)firstOrNull:(id<MDTMFlow>)receiver completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("firstOrNull(_:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)firstOrNull:(id<MDTMFlow>)receiver predicate:(id<MDTMKotlinSuspendFunction1>)predicate completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("firstOrNull(_:predicate:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)fold:(id<MDTMFlow>)receiver initial:(id _Nullable)initial operation:(id<MDTMKotlinSuspendFunction2>)operation completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("fold(_:initial:operation:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)last:(id<MDTMFlow>)receiver completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("last(_:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)lastOrNull:(id<MDTMFlow>)receiver completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("lastOrNull(_:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)reduce:(id<MDTMFlow>)receiver operation:(id<MDTMKotlinSuspendFunction2>)operation completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("reduce(_:operation:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)single:(id<MDTMFlow>)receiver completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("single(_:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)singleOrNull:(id<MDTMFlow>)receiver completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("singleOrNull(_:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ResponseObserverKt")))
@interface MDTMResponseObserverKt : MDTMBase
@property (class, readonly) id<MDTMClientPlugin> ResponseObserver __attribute__((swift_name("ResponseObserver")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SSEKt")))
@interface MDTMSSEKt : MDTMBase
@property (class, readonly) id<MDTMClientPlugin> SSE __attribute__((swift_name("SSE")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SaveBodyKt")))
@interface MDTMSaveBodyKt : MDTMBase
@property (class, readonly) id<MDTMClientPlugin> SaveBodyPlugin __attribute__((swift_name("SaveBodyPlugin"))) __attribute__((deprecated("This plugin is no longer needed.\nThis API is deprecated and will be removed in Ktor 4.0.0")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SelectKt")))
@interface MDTMSelectKt : MDTMBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)selectBuilder:(void (^)(id<MDTMSelectBuilder>))builder completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("select(builder:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SelectUnbiasedKt")))
@interface MDTMSelectUnbiasedKt : MDTMBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)selectUnbiasedBuilder:(void (^)(id<MDTMSelectBuilder>))builder completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("selectUnbiased(builder:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SemaphoreKt")))
@interface MDTMSemaphoreKt : MDTMBase
+ (id<MDTMSemaphore>)SemaphorePermits:(int32_t)permits acquiredPermits:(int32_t)acquiredPermits __attribute__((swift_name("Semaphore(permits:acquiredPermits:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)withPermit:(id<MDTMSemaphore>)receiver action:(id _Nullable (^)(void))action completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("withPermit(_:action:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ShareKt")))
@interface MDTMShareKt : MDTMBase
+ (id<MDTMSharedFlow>)asSharedFlow:(id<MDTMMutableSharedFlow>)receiver __attribute__((swift_name("asSharedFlow(_:)")));
+ (id<MDTMStateFlow>)asStateFlow:(id<MDTMMutableStateFlow>)receiver __attribute__((swift_name("asStateFlow(_:)")));
+ (id<MDTMSharedFlow>)onSubscription:(id<MDTMSharedFlow>)receiver action:(id<MDTMKotlinSuspendFunction1>)action __attribute__((swift_name("onSubscription(_:action:)")));
+ (id<MDTMSharedFlow>)shareIn:(id<MDTMFlow>)receiver scope:(id<MDTMCoroutineScope>)scope started:(id<MDTMSharingStarted>)started replay:(int32_t)replay __attribute__((swift_name("shareIn(_:scope:started:replay:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)stateIn:(id<MDTMFlow>)receiver scope:(id<MDTMCoroutineScope>)scope completionHandler:(void (^)(id<MDTMStateFlow> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("stateIn(_:scope:completionHandler:)")));
+ (id<MDTMStateFlow>)stateIn:(id<MDTMFlow>)receiver scope:(id<MDTMCoroutineScope>)scope started:(id<MDTMSharingStarted>)started initialValue:(id _Nullable)initialValue __attribute__((swift_name("stateIn(_:scope:started:initialValue:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SharedFlowKt")))
@interface MDTMSharedFlowKt : MDTMBase
+ (id<MDTMMutableSharedFlow>)MutableSharedFlowReplay:(int32_t)replay extraBufferCapacity:(int32_t)extraBufferCapacity onBufferOverflow:(MDTMBufferOverflow *)onBufferOverflow __attribute__((swift_name("MutableSharedFlow(replay:extraBufferCapacity:onBufferOverflow:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("StateFlowKt")))
@interface MDTMStateFlowKt : MDTMBase
+ (id<MDTMMutableStateFlow>)MutableStateFlowValue:(id _Nullable)value __attribute__((swift_name("MutableStateFlow(value:)")));
+ (id _Nullable)getAndUpdate:(id<MDTMMutableStateFlow>)receiver function:(id _Nullable (^)(id _Nullable))function __attribute__((swift_name("getAndUpdate(_:function:)")));
+ (void)update:(id<MDTMMutableStateFlow>)receiver function:(id _Nullable (^)(id _Nullable))function __attribute__((swift_name("update(_:function:)")));
+ (id _Nullable)updateAndGet:(id<MDTMMutableStateFlow>)receiver function:(id _Nullable (^)(id _Nullable))function __attribute__((swift_name("updateAndGet(_:function:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SupervisorKt")))
@interface MDTMSupervisorKt : MDTMBase
+ (id<MDTMCompletableJob>)SupervisorJobParent:(id<MDTMJob> _Nullable)parent __attribute__((swift_name("SupervisorJob(parent:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)supervisorScopeBlock:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("supervisorScope(block:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Synchronized_commonKt")))
@interface MDTMSynchronized_commonKt : MDTMBase

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
+ (id _Nullable)synchronizedLock:(MDTMAtomicfuSynchronizedObject *)lock block:(id _Nullable (^)(void))block __attribute__((swift_name("synchronized(lock:block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SynchronizedKt")))
@interface MDTMSynchronizedKt : MDTMBase

/**
 * @note annotations
 *   kotlinx.coroutines.InternalCoroutinesApi
*/
+ (id _Nullable)synchronizedImplLock:(MDTMAtomicfuSynchronizedObject *)lock block:(id _Nullable (^)(void))block __attribute__((swift_name("synchronizedImpl(lock:block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimeoutKt")))
@interface MDTMTimeoutKt : MDTMBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)withTimeoutTimeMillis:(int64_t)timeMillis block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("withTimeout(timeMillis:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)withTimeoutTimeout:(int64_t)timeout block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("withTimeout(timeout:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)withTimeoutOrNullTimeMillis:(int64_t)timeMillis block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("withTimeoutOrNull(timeMillis:block:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)withTimeoutOrNullTimeout:(int64_t)timeout block:(id<MDTMKotlinSuspendFunction1>)block completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("withTimeoutOrNull(timeout:block:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimeoutExceptions_nonJvmKt")))
@interface MDTMTimeoutExceptions_nonJvmKt : MDTMBase
+ (MDTMSocketTimeoutException *)SocketTimeoutExceptionMessage:(NSString *)message cause:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("SocketTimeoutException(message:cause:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TransformKt")))
@interface MDTMTransformKt : MDTMBase

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
*/
+ (id<MDTMFlow>)chunked:(id<MDTMFlow>)receiver size:(int32_t)size __attribute__((swift_name("chunked(_:size:)")));
+ (id<MDTMFlow>)filter:(id<MDTMFlow>)receiver predicate:(id<MDTMKotlinSuspendFunction1>)predicate __attribute__((swift_name("filter(_:predicate:)")));
+ (id<MDTMFlow>)filterIsInstance:(id<MDTMFlow>)receiver __attribute__((swift_name("filterIsInstance(_:)")));
+ (id<MDTMFlow>)filterIsInstance:(id<MDTMFlow>)receiver klass:(id<MDTMKotlinKClass>)klass __attribute__((swift_name("filterIsInstance(_:klass:)")));
+ (id<MDTMFlow>)filterNot:(id<MDTMFlow>)receiver predicate:(id<MDTMKotlinSuspendFunction1>)predicate __attribute__((swift_name("filterNot(_:predicate:)")));
+ (id<MDTMFlow>)filterNotNull:(id<MDTMFlow>)receiver __attribute__((swift_name("filterNotNull(_:)")));
+ (id<MDTMFlow>)map:(id<MDTMFlow>)receiver transform:(id<MDTMKotlinSuspendFunction1>)transform __attribute__((swift_name("map(_:transform:)")));
+ (id<MDTMFlow>)mapNotNull:(id<MDTMFlow>)receiver transform:(id<MDTMKotlinSuspendFunction1>)transform __attribute__((swift_name("mapNotNull(_:transform:)")));
+ (id<MDTMFlow>)onEach:(id<MDTMFlow>)receiver action:(id<MDTMKotlinSuspendFunction1>)action __attribute__((swift_name("onEach(_:action:)")));
+ (id<MDTMFlow>)runningFold:(id<MDTMFlow>)receiver initial:(id _Nullable)initial operation:(id<MDTMKotlinSuspendFunction2>)operation __attribute__((swift_name("runningFold(_:initial:operation:)")));
+ (id<MDTMFlow>)runningReduce:(id<MDTMFlow>)receiver operation:(id<MDTMKotlinSuspendFunction2>)operation __attribute__((swift_name("runningReduce(_:operation:)")));
+ (id<MDTMFlow>)scan:(id<MDTMFlow>)receiver initial:(id _Nullable)initial operation:(id<MDTMKotlinSuspendFunction2>)operation __attribute__((swift_name("scan(_:initial:operation:)")));
+ (id<MDTMFlow>)withIndex:(id<MDTMFlow>)receiver __attribute__((swift_name("withIndex(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UserAgentKt")))
@interface MDTMUserAgentKt : MDTMBase
@property (class, readonly) id<MDTMClientPlugin> UserAgent __attribute__((swift_name("UserAgent")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UtilsKt")))
@interface MDTMUtilsKt : MDTMBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)callContextWithCompletionHandler:(void (^)(id<MDTMKotlinCoroutineContext> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("callContext(completionHandler:)")));
+ (void)mergeHeadersRequestHeaders:(id<MDTMKtor_httpHeaders>)requestHeaders content:(MDTMKtor_httpOutgoingContent *)content block:(void (^)(NSString *, NSString *))block __attribute__((swift_name("mergeHeaders(requestHeaders:content:block:)")));
@property (class, readonly) NSString *KTOR_DEFAULT_USER_AGENT __attribute__((swift_name("KTOR_DEFAULT_USER_AGENT")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("WhileSelectKt")))
@interface MDTMWhileSelectKt : MDTMBase

/**
 * @note annotations
 *   kotlinx.coroutines.ExperimentalCoroutinesApi
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)whileSelectBuilder:(void (^)(id<MDTMSelectBuilder>))builder completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("whileSelect(builder:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("YieldKt")))
@interface MDTMYieldKt : MDTMBase

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
+ (void)yieldWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("yield(completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ZipKt")))
@interface MDTMZipKt : MDTMBase
+ (id<MDTMFlow>)combineFlows:(MDTMKotlinArray<id<MDTMFlow>> *)flows transform:(id<MDTMKotlinSuspendFunction1>)transform __attribute__((swift_name("combine(flows:transform:)")));
+ (id<MDTMFlow>)combineFlows:(id)flows transform_:(id<MDTMKotlinSuspendFunction1>)transform __attribute__((swift_name("combine(flows:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="flowCombine")
*/
+ (id<MDTMFlow>)combine:(id<MDTMFlow>)receiver flow:(id<MDTMFlow>)flow transform:(id<MDTMKotlinSuspendFunction2>)transform __attribute__((swift_name("combine(_:flow:transform:)")));
+ (id<MDTMFlow>)combineFlow:(id<MDTMFlow>)flow flow2:(id<MDTMFlow>)flow2 transform:(id<MDTMKotlinSuspendFunction2>)transform __attribute__((swift_name("combine(flow:flow2:transform:)")));
+ (id<MDTMFlow>)combineFlow:(id<MDTMFlow>)flow flow2:(id<MDTMFlow>)flow2 flow3:(id<MDTMFlow>)flow3 transform:(id<MDTMKotlinSuspendFunction3>)transform __attribute__((swift_name("combine(flow:flow2:flow3:transform:)")));
+ (id<MDTMFlow>)combineFlow:(id<MDTMFlow>)flow flow2:(id<MDTMFlow>)flow2 flow3:(id<MDTMFlow>)flow3 flow4:(id<MDTMFlow>)flow4 transform:(id<MDTMKotlinSuspendFunction4>)transform __attribute__((swift_name("combine(flow:flow2:flow3:flow4:transform:)")));
+ (id<MDTMFlow>)combineFlow:(id<MDTMFlow>)flow flow2:(id<MDTMFlow>)flow2 flow3:(id<MDTMFlow>)flow3 flow4:(id<MDTMFlow>)flow4 flow5:(id<MDTMFlow>)flow5 transform:(id<MDTMKotlinSuspendFunction5>)transform __attribute__((swift_name("combine(flow:flow2:flow3:flow4:flow5:transform:)")));
+ (id<MDTMFlow>)combineTransformFlows:(MDTMKotlinArray<id<MDTMFlow>> *)flows transform:(id<MDTMKotlinSuspendFunction2>)transform __attribute__((swift_name("combineTransform(flows:transform:)")));
+ (id<MDTMFlow>)combineTransformFlows:(id)flows transform_:(id<MDTMKotlinSuspendFunction2>)transform __attribute__((swift_name("combineTransform(flows:transform_:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmName(name="flowCombineTransform")
*/
+ (id<MDTMFlow>)combineTransform:(id<MDTMFlow>)receiver flow:(id<MDTMFlow>)flow transform:(id<MDTMKotlinSuspendFunction3>)transform __attribute__((swift_name("combineTransform(_:flow:transform:)")));
+ (id<MDTMFlow>)combineTransformFlow:(id<MDTMFlow>)flow flow2:(id<MDTMFlow>)flow2 transform:(id<MDTMKotlinSuspendFunction3>)transform __attribute__((swift_name("combineTransform(flow:flow2:transform:)")));
+ (id<MDTMFlow>)combineTransformFlow:(id<MDTMFlow>)flow flow2:(id<MDTMFlow>)flow2 flow3:(id<MDTMFlow>)flow3 transform:(id<MDTMKotlinSuspendFunction4>)transform __attribute__((swift_name("combineTransform(flow:flow2:flow3:transform:)")));
+ (id<MDTMFlow>)combineTransformFlow:(id<MDTMFlow>)flow flow2:(id<MDTMFlow>)flow2 flow3:(id<MDTMFlow>)flow3 flow4:(id<MDTMFlow>)flow4 transform:(id<MDTMKotlinSuspendFunction5>)transform __attribute__((swift_name("combineTransform(flow:flow2:flow3:flow4:transform:)")));
+ (id<MDTMFlow>)combineTransformFlow:(id<MDTMFlow>)flow flow2:(id<MDTMFlow>)flow2 flow3:(id<MDTMFlow>)flow3 flow4:(id<MDTMFlow>)flow4 flow5:(id<MDTMFlow>)flow5 transform:(id<MDTMKotlinSuspendFunction6>)transform __attribute__((swift_name("combineTransform(flow:flow2:flow3:flow4:flow5:transform:)")));
+ (id<MDTMFlow>)zip:(id<MDTMFlow>)receiver other:(id<MDTMFlow>)other transform:(id<MDTMKotlinSuspendFunction2>)transform __attribute__((swift_name("zip(_:other:transform:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BuildersKt_")))
@interface MDTMBuildersKt_ : MDTMBase
+ (MDTMHttpRequestBuilder *)requestBlock:(void (^)(MDTMHttpRequestBuilder *))block __attribute__((swift_name("request(block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FormDslKt")))
@interface MDTMFormDslKt : MDTMBase
+ (NSArray<MDTMKtor_httpPartData *> *)formDataValues:(MDTMKotlinArray<MDTMFormPart<id> *> *)values __attribute__((swift_name("formData(values:)")));
+ (NSArray<MDTMKtor_httpPartData *> *)formDataBlock:(void (^)(MDTMFormBuilder *))block __attribute__((swift_name("formData(block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HeadersKt")))
@interface MDTMHeadersKt : MDTMBase
+ (id<MDTMKtor_httpHeaders>)buildHeadersBlock:(void (^)(MDTMKtor_httpHeadersBuilder *))block __attribute__((swift_name("buildHeaders(block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UtilsKt_")))
@interface MDTMUtilsKt_ : MDTMBase
+ (void)accept:(id<MDTMKtor_httpHttpMessageBuilder>)receiver contentType:(MDTMKtor_httpContentType *)contentType __attribute__((swift_name("accept(_:contentType:)")));
+ (void)basicAuth:(id<MDTMKtor_httpHttpMessageBuilder>)receiver username:(NSString *)username password:(NSString *)password __attribute__((swift_name("basicAuth(_:username:password:)")));
+ (void)bearerAuth:(id<MDTMKtor_httpHttpMessageBuilder>)receiver token:(NSString *)token __attribute__((swift_name("bearerAuth(_:token:)")));
+ (void)cookie:(id<MDTMKtor_httpHttpMessageBuilder>)receiver name:(NSString *)name value:(NSString *)value maxAge:(int32_t)maxAge expires:(MDTMKtor_utilsGMTDate * _Nullable)expires domain:(NSString * _Nullable)domain path:(NSString * _Nullable)path secure:(BOOL)secure httpOnly:(BOOL)httpOnly extensions:(NSDictionary<NSString *, id> *)extensions __attribute__((swift_name("cookie(_:name:value:maxAge:expires:domain:path:secure:httpOnly:extensions:)")));
+ (void)header:(id<MDTMKtor_httpHttpMessageBuilder>)receiver key:(NSString *)key value:(id _Nullable)value __attribute__((swift_name("header(_:key:value:)")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializationStrategy")))
@protocol MDTMKotlinx_serialization_coreSerializationStrategy
@required
- (void)serializeEncoder:(id<MDTMKotlinx_serialization_coreEncoder>)encoder value:(id _Nullable)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<MDTMKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDeserializationStrategy")))
@protocol MDTMKotlinx_serialization_coreDeserializationStrategy
@required
- (id _Nullable)deserializeDecoder:(id<MDTMKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
@property (readonly) id<MDTMKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreKSerializer")))
@protocol MDTMKotlinx_serialization_coreKSerializer <MDTMKotlinx_serialization_coreSerializationStrategy, MDTMKotlinx_serialization_coreDeserializationStrategy>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface MDTMKotlinEnumCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/serialization/json/JsonElementSerializer))
*/
__attribute__((swift_name("Kotlinx_serialization_jsonJsonElement")))
@interface MDTMKotlinx_serialization_jsonJsonElement : MDTMBase
@property (class, readonly, getter=companion) MDTMKotlinx_serialization_jsonJsonElementCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinByteArray")))
@interface MDTMKotlinByteArray : MDTMBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(MDTMByte *(^)(MDTMInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (MDTMKotlinByteIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("Ktor_utilsAttributes")))
@protocol MDTMKtor_utilsAttributes
@required
- (id)computeIfAbsentKey:(MDTMKtor_utilsAttributeKey<id> *)key block:(id (^)(void))block __attribute__((swift_name("computeIfAbsent(key:block:)")));
- (BOOL)containsKey:(MDTMKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("contains(key:)")));
- (id)getKey_:(MDTMKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("get(key_:)")));
- (id _Nullable)getOrNullKey:(MDTMKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("getOrNull(key:)")));
- (void)putKey:(MDTMKtor_utilsAttributeKey<id> *)key value:(id)value __attribute__((swift_name("put(key:value:)")));
- (void)removeKey:(MDTMKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("remove(key:)")));
- (void)setKey:(MDTMKtor_utilsAttributeKey<id> *)key value:(id)value __attribute__((swift_name("set(key:value:)")));
- (id)takeKey:(MDTMKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("take(key:)")));
- (id _Nullable)takeOrNullKey:(MDTMKtor_utilsAttributeKey<id> *)key __attribute__((swift_name("takeOrNull(key:)")));
@property (readonly) NSArray<MDTMKtor_utilsAttributeKey<id> *> *allKeys __attribute__((swift_name("allKeys")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_eventsEvents")))
@interface MDTMKtor_eventsEvents : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)raiseDefinition:(MDTMKtor_eventsEventDefinition<id> *)definition value:(id _Nullable)value __attribute__((swift_name("raise(definition:value:)")));
- (id<MDTMDisposableHandle>)subscribeDefinition:(MDTMKtor_eventsEventDefinition<id> *)definition handler:(void (^)(id _Nullable))handler __attribute__((swift_name("subscribe(definition:handler:)")));
- (void)unsubscribeDefinition:(MDTMKtor_eventsEventDefinition<id> *)definition handler:(void (^)(id _Nullable))handler __attribute__((swift_name("unsubscribe(definition:handler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsTypeInfo")))
@interface MDTMKtor_utilsTypeInfo : MDTMBase
- (instancetype)initWithType:(id<MDTMKotlinKClass>)type kotlinType:(id<MDTMKotlinKType> _Nullable)kotlinType __attribute__((swift_name("init(type:kotlinType:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithType:(id<MDTMKotlinKClass>)type reifiedType:(id<MDTMKotlinKType>)reifiedType kotlinType:(id<MDTMKotlinKType> _Nullable)kotlinType __attribute__((swift_name("init(type:reifiedType:kotlinType:)"))) __attribute__((objc_designated_initializer)) __attribute__((deprecated("Use constructor without reifiedType parameter.")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<MDTMKotlinKType> _Nullable kotlinType __attribute__((swift_name("kotlinType")));
@property (readonly) id<MDTMKotlinKClass> type __attribute__((swift_name("type")));
@end

__attribute__((swift_name("Ktor_ioByteReadChannel")))
@protocol MDTMKtor_ioByteReadChannel
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)awaitContentMin:(int32_t)min completionHandler:(void (^)(MDTMBoolean * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("awaitContent(min:completionHandler:)")));
- (void)cancelCause__:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("cancel(cause__:)")));
@property (readonly) MDTMKotlinThrowable * _Nullable closedCause __attribute__((swift_name("closedCause")));
@property (readonly) BOOL isClosedForRead __attribute__((swift_name("isClosedForRead")));
@property (readonly) id<MDTMKotlinx_io_coreSource> readBuffer __attribute__((swift_name("readBuffer")));
@end

__attribute__((swift_name("KotlinKDeclarationContainer")))
@protocol MDTMKotlinKDeclarationContainer
@required
@end

__attribute__((swift_name("KotlinKAnnotatedElement")))
@protocol MDTMKotlinKAnnotatedElement
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((swift_name("KotlinKClassifier")))
@protocol MDTMKotlinKClassifier
@required
@end

__attribute__((swift_name("KotlinKClass")))
@protocol MDTMKotlinKClass <MDTMKotlinKDeclarationContainer, MDTMKotlinKAnnotatedElement, MDTMKotlinKClassifier>
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
- (BOOL)isInstanceValue:(id _Nullable)value __attribute__((swift_name("isInstance(value:)")));
@property (readonly) NSString * _Nullable qualifiedName __attribute__((swift_name("qualifiedName")));
@property (readonly) NSString * _Nullable simpleName __attribute__((swift_name("simpleName")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=io/ktor/http/UrlSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpUrl")))
@interface MDTMKtor_httpUrl : MDTMBase <MDTMKtor_ioJvmSerializable>
@property (class, readonly, getter=companion) MDTMKtor_httpUrlCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *encodedFragment __attribute__((swift_name("encodedFragment")));
@property (readonly) NSString * _Nullable encodedPassword __attribute__((swift_name("encodedPassword")));
@property (readonly) NSString *encodedPath __attribute__((swift_name("encodedPath")));
@property (readonly) NSString *encodedPathAndQuery __attribute__((swift_name("encodedPathAndQuery")));
@property (readonly) NSString *encodedQuery __attribute__((swift_name("encodedQuery")));
@property (readonly) NSString * _Nullable encodedUser __attribute__((swift_name("encodedUser")));
@property (readonly) NSString *fragment __attribute__((swift_name("fragment")));
@property (readonly) NSString *host __attribute__((swift_name("host")));
@property (readonly) id<MDTMKtor_httpParameters> parameters __attribute__((swift_name("parameters")));
@property (readonly) NSString * _Nullable password __attribute__((swift_name("password")));
@property (readonly) NSArray<NSString *> *pathSegments __attribute__((swift_name("pathSegments"))) __attribute__((deprecated("\n        `pathSegments` is deprecated.\n\n        This property will contain an empty path segment at the beginning for URLs with a hostname,\n        and an empty path segment at the end for the URLs with a trailing slash. If you need to keep this behaviour please\n        use [rawSegments]. If you only need to access the meaningful parts of the path, consider using [segments] instead.\n             \n        Please decide if you need [rawSegments] or [segments] explicitly.\n        ")));
@property (readonly) int32_t port __attribute__((swift_name("port")));
@property (readonly) MDTMKtor_httpURLProtocol *protocol __attribute__((swift_name("protocol")));
@property (readonly) MDTMKtor_httpURLProtocol * _Nullable protocolOrNull __attribute__((swift_name("protocolOrNull")));
@property (readonly) NSArray<NSString *> *rawSegments __attribute__((swift_name("rawSegments")));
@property (readonly) NSArray<NSString *> *segments __attribute__((swift_name("segments")));
@property (readonly) int32_t specifiedPort __attribute__((swift_name("specifiedPort")));
@property (readonly) BOOL trailingQuery __attribute__((swift_name("trailingQuery")));
@property (readonly) NSString * _Nullable user __attribute__((swift_name("user")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol MDTMKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsAttributeKey")))
@interface MDTMKtor_utilsAttributeKey<T> : MDTMBase

/**
 * @note annotations
 *   kotlin.jvm.JvmOverloads
*/
- (instancetype)initWithName:(NSString *)name type:(MDTMKtor_utilsTypeInfo *)type __attribute__((swift_name("init(name:type:)"))) __attribute__((objc_designated_initializer));
- (MDTMKtor_utilsAttributeKey<T> *)doCopyName:(NSString *)name type:(MDTMKtor_utilsTypeInfo *)type __attribute__((swift_name("doCopy(name:type:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((swift_name("Ktor_utilsConversionService")))
@protocol MDTMKtor_utilsConversionService
@required
- (id _Nullable)fromValuesValues:(NSArray<NSString *> *)values type:(MDTMKtor_utilsTypeInfo *)type __attribute__((swift_name("fromValues(values:type:)")));
- (NSArray<NSString *> *)toValuesValue:(id _Nullable)value __attribute__((swift_name("toValues(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsDataConversion")))
@interface MDTMKtor_utilsDataConversion : MDTMBase <MDTMKtor_utilsConversionService>
- (instancetype)initWithConfiguration:(MDTMKtor_utilsDataConversionConfiguration *)configuration __attribute__((swift_name("init(configuration:)"))) __attribute__((objc_designated_initializer));
- (id _Nullable)fromValuesValues:(NSArray<NSString *> *)values type:(MDTMKtor_utilsTypeInfo *)type __attribute__((swift_name("fromValues(values:type:)")));
- (NSArray<NSString *> *)toValuesValue:(id _Nullable)value __attribute__((swift_name("toValues(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsDataConversion.Configuration")))
@interface MDTMKtor_utilsDataConversionConfiguration : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)convertConfigure:(void (^)(MDTMKtor_utilsDelegatingConversionServiceConfiguration<id> *))configure __attribute__((swift_name("convert(configure:)")));
- (void)convertType:(id<MDTMKotlinKClass>)type convertor:(id<MDTMKtor_utilsConversionService>)convertor __attribute__((swift_name("convert(type:convertor:)")));
- (void)convertType:(id<MDTMKotlinKType>)type configure:(void (^)(MDTMKtor_utilsDelegatingConversionServiceConfiguration<id> *))configure __attribute__((swift_name("convert(type:configure:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLBuilder")))
@interface MDTMKtor_httpURLBuilder : MDTMBase
- (instancetype)initWithProtocol:(MDTMKtor_httpURLProtocol * _Nullable)protocol host:(NSString *)host port:(int32_t)port user:(NSString * _Nullable)user password:(NSString * _Nullable)password pathSegments:(NSArray<NSString *> *)pathSegments parameters:(id<MDTMKtor_httpParameters>)parameters fragment:(NSString *)fragment trailingQuery:(BOOL)trailingQuery __attribute__((swift_name("init(protocol:host:port:user:password:pathSegments:parameters:fragment:trailingQuery:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMKtor_httpURLBuilderCompanion *companion __attribute__((swift_name("companion")));
- (MDTMKtor_httpUrl *)build __attribute__((swift_name("build()")));
- (NSString *)buildString __attribute__((swift_name("buildString()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property NSString *encodedFragment __attribute__((swift_name("encodedFragment")));
@property id<MDTMKtor_httpParametersBuilder> encodedParameters __attribute__((swift_name("encodedParameters")));
@property NSString * _Nullable encodedPassword __attribute__((swift_name("encodedPassword")));
@property NSArray<NSString *> *encodedPathSegments __attribute__((swift_name("encodedPathSegments")));
@property NSString * _Nullable encodedUser __attribute__((swift_name("encodedUser")));
@property NSString *fragment __attribute__((swift_name("fragment")));
@property NSString *host __attribute__((swift_name("host")));
@property (readonly) id<MDTMKtor_httpParametersBuilder> parameters __attribute__((swift_name("parameters")));
@property NSString * _Nullable password __attribute__((swift_name("password")));
@property NSArray<NSString *> *pathSegments __attribute__((swift_name("pathSegments")));
@property int32_t port __attribute__((swift_name("port")));
@property MDTMKtor_httpURLProtocol *protocol __attribute__((swift_name("protocol")));
@property MDTMKtor_httpURLProtocol * _Nullable protocolOrNull __attribute__((swift_name("protocolOrNull")));
@property BOOL trailingQuery __attribute__((swift_name("trailingQuery")));
@property NSString * _Nullable user __attribute__((swift_name("user")));
@end

__attribute__((swift_name("KotlinFunction")))
@protocol MDTMKotlinFunction
@required
@end

__attribute__((swift_name("KotlinSuspendFunction2")))
@protocol MDTMKotlinSuspendFunction2 <MDTMKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeP1:(id _Nullable)p1 p2:(id _Nullable)p2 completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(p1:p2:completionHandler:)")));
@end

__attribute__((swift_name("KotlinSuspendFunction1")))
@protocol MDTMKotlinSuspendFunction1 <MDTMKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeP1:(id _Nullable)p1 completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(p1:completionHandler:)")));
@end

__attribute__((swift_name("Ktor_ioCharset")))
@interface MDTMKtor_ioCharset : MDTMBase
- (instancetype)initWith_name:(NSString *)_name __attribute__((swift_name("init(_name:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMKtor_ioCharsetCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (MDTMKtor_ioCharsetDecoder *)doNewDecoder __attribute__((swift_name("doNewDecoder()")));
- (MDTMKtor_ioCharsetEncoder *)doNewEncoder __attribute__((swift_name("doNewEncoder()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("KotlinSuspendFunction3")))
@protocol MDTMKotlinSuspendFunction3 <MDTMKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeP1:(id _Nullable)p1 p2:(id _Nullable)p2 p3:(id _Nullable)p3 completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(p1:p2:p3:completionHandler:)")));
@end

__attribute__((swift_name("KotlinSuspendFunction4")))
@protocol MDTMKotlinSuspendFunction4 <MDTMKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeP1:(id _Nullable)p1 p2:(id _Nullable)p2 p3:(id _Nullable)p3 p4:(id _Nullable)p4 completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(p1:p2:p3:p4:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinUnit")))
@interface MDTMKotlinUnit : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)unit __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKotlinUnit *shared __attribute__((swift_name("shared")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Ktor_eventsEventDefinition")))
@interface MDTMKtor_eventsEventDefinition<T> : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsGMTDate")))
@interface MDTMKtor_utilsGMTDate : MDTMBase <MDTMKotlinComparable>
- (instancetype)initWithSeconds:(int32_t)seconds minutes:(int32_t)minutes hours:(int32_t)hours dayOfWeek:(MDTMKtor_utilsWeekDay *)dayOfWeek dayOfMonth:(int32_t)dayOfMonth dayOfYear:(int32_t)dayOfYear month:(MDTMKtor_utilsMonth *)month year:(int32_t)year timestamp:(int64_t)timestamp __attribute__((swift_name("init(seconds:minutes:hours:dayOfWeek:dayOfMonth:dayOfYear:month:year:timestamp:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMKtor_utilsGMTDateCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(MDTMKtor_utilsGMTDate *)other __attribute__((swift_name("compareTo(other:)")));
- (MDTMKtor_utilsGMTDate *)doCopy __attribute__((swift_name("doCopy()")));
- (MDTMKtor_utilsGMTDate *)doCopySeconds:(int32_t)seconds minutes:(int32_t)minutes hours:(int32_t)hours dayOfWeek:(MDTMKtor_utilsWeekDay *)dayOfWeek dayOfMonth:(int32_t)dayOfMonth dayOfYear:(int32_t)dayOfYear month:(MDTMKtor_utilsMonth *)month year:(int32_t)year timestamp:(int64_t)timestamp __attribute__((swift_name("doCopy(seconds:minutes:hours:dayOfWeek:dayOfMonth:dayOfYear:month:year:timestamp:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t dayOfMonth __attribute__((swift_name("dayOfMonth")));
@property (readonly) MDTMKtor_utilsWeekDay *dayOfWeek __attribute__((swift_name("dayOfWeek")));
@property (readonly) int32_t dayOfYear __attribute__((swift_name("dayOfYear")));
@property (readonly) int32_t hours __attribute__((swift_name("hours")));
@property (readonly) int32_t minutes __attribute__((swift_name("minutes")));
@property (readonly) MDTMKtor_utilsMonth *month __attribute__((swift_name("month")));
@property (readonly) int32_t seconds __attribute__((swift_name("seconds")));
@property (readonly) int64_t timestamp __attribute__((swift_name("timestamp")));
@property (readonly) int32_t year __attribute__((swift_name("year")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpStatusCode")))
@interface MDTMKtor_httpHttpStatusCode : MDTMBase <MDTMKotlinComparable>
- (instancetype)initWithValue:(int32_t)value description:(NSString *)description __attribute__((swift_name("init(value:description:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMKtor_httpHttpStatusCodeCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(MDTMKtor_httpHttpStatusCode *)other __attribute__((swift_name("compareTo(other:)")));
- (MDTMKtor_httpHttpStatusCode *)doCopyValue:(int32_t)value description:(NSString *)description __attribute__((swift_name("doCopy(value:description:)")));
- (MDTMKtor_httpHttpStatusCode *)descriptionValue:(NSString *)value __attribute__((swift_name("description(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *description_ __attribute__((swift_name("description_")));
@property (readonly) int32_t value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpProtocolVersion")))
@interface MDTMKtor_httpHttpProtocolVersion : MDTMBase
- (instancetype)initWithName:(NSString *)name major:(int32_t)major minor:(int32_t)minor __attribute__((swift_name("init(name:major:minor:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMKtor_httpHttpProtocolVersionCompanion *companion __attribute__((swift_name("companion")));
- (MDTMKtor_httpHttpProtocolVersion *)doCopyName:(NSString *)name major:(int32_t)major minor:(int32_t)minor __attribute__((swift_name("doCopy(name:major:minor:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t major __attribute__((swift_name("major")));
@property (readonly) int32_t minor __attribute__((swift_name("minor")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((swift_name("Ktor_utilsStringValues")))
@protocol MDTMKtor_utilsStringValues
@required
- (BOOL)containsName:(NSString *)name __attribute__((swift_name("contains(name:)")));
- (BOOL)containsName:(NSString *)name value:(NSString *)value __attribute__((swift_name("contains(name:value:)")));
- (NSSet<id<MDTMKotlinMapEntry>> *)entries __attribute__((swift_name("entries()")));
- (void)forEachBody:(void (^)(NSString *, NSArray<NSString *> *))body __attribute__((swift_name("forEach(body:)")));
- (NSString * _Nullable)getName:(NSString *)name __attribute__((swift_name("get(name:)")));
- (NSArray<NSString *> * _Nullable)getAllName:(NSString *)name __attribute__((swift_name("getAll(name:)")));
- (BOOL)isEmpty_ __attribute__((swift_name("isEmpty()")));
- (NSSet<NSString *> *)names __attribute__((swift_name("names()")));
@property (readonly) BOOL caseInsensitiveName __attribute__((swift_name("caseInsensitiveName")));
@end

__attribute__((swift_name("Ktor_httpHeaders")))
@protocol MDTMKtor_httpHeaders <MDTMKtor_utilsStringValues>
@required
@end

__attribute__((swift_name("Ktor_httpHeaderValueWithParameters")))
@interface MDTMKtor_httpHeaderValueWithParameters : MDTMBase
- (instancetype)initWithContent:(NSString *)content parameters:(NSArray<MDTMKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(content:parameters:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMKtor_httpHeaderValueWithParametersCompanion *companion __attribute__((swift_name("companion")));
- (NSString * _Nullable)parameterName:(NSString *)name __attribute__((swift_name("parameter(name:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note This property has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
@property (readonly) NSString *content __attribute__((swift_name("content")));
@property (readonly) NSArray<MDTMKtor_httpHeaderValueParam *> *parameters __attribute__((swift_name("parameters")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpContentType")))
@interface MDTMKtor_httpContentType : MDTMKtor_httpHeaderValueWithParameters
- (instancetype)initWithContentType:(NSString *)contentType contentSubtype:(NSString *)contentSubtype parameters:(NSArray<MDTMKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(contentType:contentSubtype:parameters:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithContent:(NSString *)content parameters:(NSArray<MDTMKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(content:parameters:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) MDTMKtor_httpContentTypeCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)matchPattern:(MDTMKtor_httpContentType *)pattern __attribute__((swift_name("match(pattern:)")));
- (BOOL)matchPattern_:(NSString *)pattern __attribute__((swift_name("match(pattern_:)")));
- (MDTMKtor_httpContentType *)withParameterName:(NSString *)name value:(NSString *)value __attribute__((swift_name("withParameter(name:value:)")));
- (MDTMKtor_httpContentType *)withoutParameters __attribute__((swift_name("withoutParameters()")));
@property (readonly) NSString *contentSubtype __attribute__((swift_name("contentSubtype")));
@property (readonly) NSString *contentType __attribute__((swift_name("contentType")));
@end

__attribute__((swift_name("Ktor_serializationContentConverter")))
@protocol MDTMKtor_serializationContentConverter
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deserializeCharset:(MDTMKtor_ioCharset *)charset typeInfo:(MDTMKtor_utilsTypeInfo *)typeInfo content:(id<MDTMKtor_ioByteReadChannel>)content completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("deserialize(charset:typeInfo:content:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)serializeContentType:(MDTMKtor_httpContentType *)contentType charset:(MDTMKtor_ioCharset *)charset typeInfo:(MDTMKtor_utilsTypeInfo *)typeInfo value:(id _Nullable)value completionHandler:(void (^)(MDTMKtor_httpOutgoingContent * _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("serialize(contentType:charset:typeInfo:value:completionHandler:)")));
@end

__attribute__((swift_name("Ktor_websocketsFrame")))
@interface MDTMKtor_websocketsFrame : MDTMBase
@property (class, readonly, getter=companion) MDTMKtor_websocketsFrameCompanion *companion __attribute__((swift_name("companion")));
- (MDTMKtor_websocketsFrame *)doCopy __attribute__((swift_name("doCopy()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) MDTMKotlinByteArray *data __attribute__((swift_name("data")));
@property (readonly) id<MDTMDisposableHandle> disposableHandle __attribute__((swift_name("disposableHandle")));
@property (readonly) BOOL fin __attribute__((swift_name("fin")));
@property (readonly) MDTMKtor_websocketsFrameType *frameType __attribute__((swift_name("frameType")));
@property (readonly) BOOL rsv1 __attribute__((swift_name("rsv1")));
@property (readonly) BOOL rsv2 __attribute__((swift_name("rsv2")));
@property (readonly) BOOL rsv3 __attribute__((swift_name("rsv3")));
@end

__attribute__((swift_name("Ktor_websocketsWebSocketExtension")))
@protocol MDTMKtor_websocketsWebSocketExtension
@required
- (BOOL)clientNegotiationNegotiatedProtocols:(NSArray<MDTMKtor_websocketsWebSocketExtensionHeader *> *)negotiatedProtocols __attribute__((swift_name("clientNegotiation(negotiatedProtocols:)")));
- (MDTMKtor_websocketsFrame *)processIncomingFrameFrame:(MDTMKtor_websocketsFrame *)frame __attribute__((swift_name("processIncomingFrame(frame:)")));
- (MDTMKtor_websocketsFrame *)processOutgoingFrameFrame:(MDTMKtor_websocketsFrame *)frame __attribute__((swift_name("processOutgoingFrame(frame:)")));
- (NSArray<MDTMKtor_websocketsWebSocketExtensionHeader *> *)serverNegotiationRequestedProtocols:(NSArray<MDTMKtor_websocketsWebSocketExtensionHeader *> *)requestedProtocols __attribute__((swift_name("serverNegotiation(requestedProtocols:)")));
@property (readonly) id<MDTMKtor_websocketsWebSocketExtensionFactory> factory __attribute__((swift_name("factory")));
@property (readonly) NSArray<MDTMKtor_websocketsWebSocketExtensionHeader *> *protocols __attribute__((swift_name("protocols")));
@end

__attribute__((swift_name("Ktor_serializationWebsocketContentConverter")))
@protocol MDTMKtor_serializationWebsocketContentConverter
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deserializeCharset:(MDTMKtor_ioCharset *)charset typeInfo:(MDTMKtor_utilsTypeInfo *)typeInfo content:(MDTMKtor_websocketsFrame *)content completionHandler_:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("deserialize(charset:typeInfo:content:completionHandler_:)")));
- (BOOL)isApplicableFrame:(MDTMKtor_websocketsFrame *)frame __attribute__((swift_name("isApplicable(frame:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)serializeCharset:(MDTMKtor_ioCharset *)charset typeInfo:(MDTMKtor_utilsTypeInfo *)typeInfo value:(id _Nullable)value completionHandler:(void (^)(MDTMKtor_websocketsFrame * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("serialize(charset:typeInfo:value:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_websocketsWebSocketExtensionsConfig")))
@interface MDTMKtor_websocketsWebSocketExtensionsConfig : MDTMBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (NSArray<id<MDTMKtor_websocketsWebSocketExtension>> *)build __attribute__((swift_name("build()")));
- (void)installExtension:(id<MDTMKtor_websocketsWebSocketExtensionFactory>)extension config:(void (^)(id))config __attribute__((swift_name("install(extension:config:)")));
@end

__attribute__((swift_name("Ktor_ioByteWriteChannel")))
@protocol MDTMKtor_ioByteWriteChannel
@required
- (void)cancelCause__:(MDTMKotlinThrowable * _Nullable)cause __attribute__((swift_name("cancel(cause__:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)flushWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("flush(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)flushAndCloseWithCompletionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("flushAndClose(completionHandler:)")));
@property (readonly) MDTMKotlinThrowable * _Nullable closedCause __attribute__((swift_name("closedCause")));
@property (readonly) BOOL isClosedForWrite __attribute__((swift_name("isClosedForWrite")));
@property (readonly) id<MDTMKotlinx_io_coreSink> writeBuffer __attribute__((swift_name("writeBuffer")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpMethod")))
@interface MDTMKtor_httpHttpMethod : MDTMBase
- (instancetype)initWithValue:(NSString *)value __attribute__((swift_name("init(value:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMKtor_httpHttpMethodCompanion *companion __attribute__((swift_name("companion")));
- (MDTMKtor_httpHttpMethod *)doCopyValue:(NSString *)value __attribute__((swift_name("doCopy(value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsPipelinePhase")))
@interface MDTMKtor_utilsPipelinePhase : MDTMBase
- (instancetype)initWithName:(NSString *)name __attribute__((swift_name("init(name:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((swift_name("Kotlinx_io_coreRawSource")))
@protocol MDTMKotlinx_io_coreRawSource <MDTMKotlinAutoCloseable>
@required
- (int64_t)readAtMostToSink:(MDTMKotlinx_io_coreBuffer *)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readAtMostTo(sink:byteCount:)")));
@end

__attribute__((swift_name("Kotlinx_io_coreSource")))
@protocol MDTMKotlinx_io_coreSource <MDTMKotlinx_io_coreRawSource>
@required
- (BOOL)exhausted __attribute__((swift_name("exhausted()")));
- (id<MDTMKotlinx_io_coreSource>)peek __attribute__((swift_name("peek()")));
- (int32_t)readAtMostToSink:(MDTMKotlinByteArray *)sink startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("readAtMostTo(sink:startIndex:endIndex:)")));
- (int8_t)readByte __attribute__((swift_name("readByte()")));
- (int32_t)readInt __attribute__((swift_name("readInt()")));
- (int64_t)readLong __attribute__((swift_name("readLong()")));
- (int16_t)readShort __attribute__((swift_name("readShort()")));
- (void)readToSink:(id<MDTMKotlinx_io_coreRawSink>)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readTo(sink:byteCount:)")));
- (BOOL)requestByteCount:(int64_t)byteCount __attribute__((swift_name("request(byteCount:)")));
- (void)requireByteCount:(int64_t)byteCount __attribute__((swift_name("require(byteCount:)")));
- (void)skipByteCount:(int64_t)byteCount __attribute__((swift_name("skip(byteCount:)")));
- (int64_t)transferToSink:(id<MDTMKotlinx_io_coreRawSink>)sink __attribute__((swift_name("transferTo(sink:)")));

/**
 * @note annotations
 *   kotlinx.io.InternalIoApi
*/
@property (readonly) MDTMKotlinx_io_coreBuffer *buffer __attribute__((swift_name("buffer")));
@end

__attribute__((swift_name("Ktor_httpParameters")))
@protocol MDTMKtor_httpParameters <MDTMKtor_utilsStringValues>
@required
@end

__attribute__((swift_name("Ktor_httpPartData")))
@interface MDTMKtor_httpPartData : MDTMBase
@property (readonly) MDTMKtor_httpContentDisposition * _Nullable contentDisposition __attribute__((swift_name("contentDisposition")));
@property (readonly) MDTMKtor_httpContentType * _Nullable contentType __attribute__((swift_name("contentType")));
@property (readonly, getter=dispose_) void (^dispose)(void) __attribute__((swift_name("dispose")));
@property (readonly) id<MDTMKtor_httpHeaders> headers __attribute__((swift_name("headers")));
@property (readonly) NSString * _Nullable name __attribute__((swift_name("name")));
@end

__attribute__((swift_name("KotlinSequence")))
@protocol MDTMKotlinSequence
@required
- (id<MDTMKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end

__attribute__((swift_name("KotlinSuspendFunction0")))
@protocol MDTMKotlinSuspendFunction0 <MDTMKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeWithCompletionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(completionHandler:)")));
@end

__attribute__((swift_name("Ktor_utilsNetworkAddress")))
@interface MDTMKtor_utilsNetworkAddress : MDTMBase
- (instancetype)initWithHostname:(NSString *)hostname port:(int32_t)port explicitAddress:(id _Nullable)explicitAddress __attribute__((swift_name("init(hostname:port:explicitAddress:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property id _Nullable explicitAddress __attribute__((swift_name("explicitAddress")));
@property (readonly) NSString *hostname __attribute__((swift_name("hostname")));
@property (readonly) int32_t port __attribute__((swift_name("port")));
@end

__attribute__((swift_name("Kotlinx_io_coreRawSink")))
@protocol MDTMKotlinx_io_coreRawSink <MDTMKotlinAutoCloseable>
@required
- (void)flush __attribute__((swift_name("flush()")));
- (void)writeSource:(MDTMKotlinx_io_coreBuffer *)source byteCount_:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount_:)")));
@end

__attribute__((swift_name("Kotlinx_io_coreSink")))
@protocol MDTMKotlinx_io_coreSink <MDTMKotlinx_io_coreRawSink>
@required
- (void)emit __attribute__((swift_name("emit()")));

/**
 * @note annotations
 *   kotlinx.io.InternalIoApi
*/
- (void)hintEmit __attribute__((swift_name("hintEmit()")));
- (int64_t)transferFromSource:(id<MDTMKotlinx_io_coreRawSource>)source __attribute__((swift_name("transferFrom(source:)")));
- (void)writeSource:(id<MDTMKotlinx_io_coreRawSource>)source byteCount:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount:)")));
- (void)writeSource:(MDTMKotlinByteArray *)source startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("write(source:startIndex:endIndex:)")));
- (void)writeByteByte:(int8_t)byte __attribute__((swift_name("writeByte(byte:)")));
- (void)writeIntInt:(int32_t)int_ __attribute__((swift_name("writeInt(int:)")));
- (void)writeLongLong:(int64_t)long_ __attribute__((swift_name("writeLong(long:)")));
- (void)writeShortShort:(int16_t)short_ __attribute__((swift_name("writeShort(short:)")));

/**
 * @note annotations
 *   kotlinx.io.InternalIoApi
*/
@property (readonly) MDTMKotlinx_io_coreBuffer *buffer __attribute__((swift_name("buffer")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpCookieEncoding")))
@interface MDTMKtor_httpCookieEncoding : MDTMKotlinEnum<MDTMKtor_httpCookieEncoding *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) MDTMKtor_httpCookieEncoding *raw __attribute__((swift_name("raw")));
@property (class, readonly) MDTMKtor_httpCookieEncoding *dquotes __attribute__((swift_name("dquotes")));
@property (class, readonly) MDTMKtor_httpCookieEncoding *uriEncoding __attribute__((swift_name("uriEncoding")));
@property (class, readonly) MDTMKtor_httpCookieEncoding *base64Encoding __attribute__((swift_name("base64Encoding")));
+ (MDTMKotlinArray<MDTMKtor_httpCookieEncoding *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<MDTMKtor_httpCookieEncoding *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpCookie.Companion")))
@interface MDTMKtor_httpCookieCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_httpCookieCompanion *shared __attribute__((swift_name("shared")));
- (id<MDTMKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((swift_name("KotlinMapEntry")))
@protocol MDTMKotlinMapEntry
@required
@property (readonly) id _Nullable key __attribute__((swift_name("key")));
@property (readonly) id _Nullable value __attribute__((swift_name("value")));
@end

__attribute__((swift_name("KotlinIntIterator")))
@interface MDTMKotlinIntIterator : MDTMBase <MDTMKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (MDTMInt *)next __attribute__((swift_name("next()")));
- (int32_t)nextInt __attribute__((swift_name("nextInt()")));
@end

__attribute__((swift_name("KotlinLongIterator")))
@interface MDTMKotlinLongIterator : MDTMBase <MDTMKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (MDTMLong *)next __attribute__((swift_name("next()")));
- (int64_t)nextLong __attribute__((swift_name("nextLong()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinIntProgression.Companion")))
@interface MDTMKotlinIntProgressionCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKotlinIntProgressionCompanion *shared __attribute__((swift_name("shared")));
- (MDTMKotlinIntProgression *)fromClosedRangeRangeStart:(int32_t)rangeStart rangeEnd:(int32_t)rangeEnd step:(int32_t)step __attribute__((swift_name("fromClosedRange(rangeStart:rangeEnd:step:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinIntRange.Companion")))
@interface MDTMKotlinIntRangeCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKotlinIntRangeCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) MDTMKotlinIntRange *EMPTY __attribute__((swift_name("EMPTY")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinLongProgression.Companion")))
@interface MDTMKotlinLongProgressionCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKotlinLongProgressionCompanion *shared __attribute__((swift_name("shared")));
- (MDTMKotlinLongProgression *)fromClosedRangeRangeStart:(int64_t)rangeStart rangeEnd:(int64_t)rangeEnd step:(int64_t)step __attribute__((swift_name("fromClosedRange(rangeStart:rangeEnd:step:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinLongRange.Companion")))
@interface MDTMKotlinLongRangeCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKotlinLongRangeCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) MDTMKotlinLongRange *EMPTY __attribute__((swift_name("EMPTY")));
@end

__attribute__((swift_name("Ktor_sseServerSentEventMetadata")))
@protocol MDTMKtor_sseServerSentEventMetadata
@required
@property (readonly) NSString * _Nullable comments __attribute__((swift_name("comments")));
@property (readonly) id _Nullable data __attribute__((swift_name("data")));
@property (readonly) NSString * _Nullable event __attribute__((swift_name("event")));
@property (readonly) NSString * _Nullable id __attribute__((swift_name("id")));
@property (readonly) MDTMLong * _Nullable retry __attribute__((swift_name("retry")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_sseTypedServerSentEvent")))
@interface MDTMKtor_sseTypedServerSentEvent<T> : MDTMBase <MDTMKtor_sseServerSentEventMetadata>
- (instancetype)initWithData:(T _Nullable)data event:(NSString * _Nullable)event id:(NSString * _Nullable)id retry:(MDTMLong * _Nullable)retry comments:(NSString * _Nullable)comments __attribute__((swift_name("init(data:event:id:retry:comments:)"))) __attribute__((objc_designated_initializer));
- (MDTMKtor_sseTypedServerSentEvent<T> *)doCopyData:(T _Nullable)data event:(NSString * _Nullable)event id:(NSString * _Nullable)id retry:(MDTMLong * _Nullable)retry comments:(NSString * _Nullable)comments __attribute__((swift_name("doCopy(data:event:id:retry:comments:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
- (NSString *)toStringSerializer:(NSString *(^)(T _Nullable))serializer __attribute__((swift_name("toString(serializer:)")));
@property (readonly) NSString * _Nullable comments __attribute__((swift_name("comments")));
@property (readonly) T _Nullable data __attribute__((swift_name("data")));
@property (readonly) NSString * _Nullable event __attribute__((swift_name("event")));
@property (readonly) NSString * _Nullable id __attribute__((swift_name("id")));
@property (readonly) MDTMLong * _Nullable retry __attribute__((swift_name("retry")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinNothing")))
@interface MDTMKotlinNothing : MDTMBase
@end

__attribute__((swift_name("KotlinSuspendFunction5")))
@protocol MDTMKotlinSuspendFunction5 <MDTMKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeP1:(id _Nullable)p1 p2:(id _Nullable)p2 p3:(id _Nullable)p3 p4:(id _Nullable)p4 p5:(id _Nullable)p5 completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(p1:p2:p3:p4:p5:completionHandler:)")));
@end

__attribute__((swift_name("KotlinSuspendFunction6")))
@protocol MDTMKotlinSuspendFunction6 <MDTMKotlinFunction>
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)invokeP1:(id _Nullable)p1 p2:(id _Nullable)p2 p3:(id _Nullable)p3 p4:(id _Nullable)p4 p5:(id _Nullable)p5 p6:(id _Nullable)p6 completionHandler:(void (^)(id _Nullable_result, NSError * _Nullable))completionHandler __attribute__((swift_name("invoke(p1:p2:p3:p4:p5:p6:completionHandler:)")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreEncoder")))
@protocol MDTMKotlinx_serialization_coreEncoder
@required
- (id<MDTMKotlinx_serialization_coreCompositeEncoder>)beginCollectionDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor collectionSize:(int32_t)collectionSize __attribute__((swift_name("beginCollection(descriptor:collectionSize:)")));
- (id<MDTMKotlinx_serialization_coreCompositeEncoder>)beginStructureDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (void)encodeBooleanValue:(BOOL)value __attribute__((swift_name("encodeBoolean(value:)")));
- (void)encodeByteValue:(int8_t)value __attribute__((swift_name("encodeByte(value:)")));
- (void)encodeCharValue:(unichar)value __attribute__((swift_name("encodeChar(value:)")));
- (void)encodeDoubleValue:(double)value __attribute__((swift_name("encodeDouble(value:)")));
- (void)encodeEnumEnumDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)enumDescriptor index:(int32_t)index __attribute__((swift_name("encodeEnum(enumDescriptor:index:)")));
- (void)encodeFloatValue:(float)value __attribute__((swift_name("encodeFloat(value:)")));
- (id<MDTMKotlinx_serialization_coreEncoder>)encodeInlineDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("encodeInline(descriptor:)")));
- (void)encodeIntValue:(int32_t)value __attribute__((swift_name("encodeInt(value:)")));
- (void)encodeLongValue:(int64_t)value __attribute__((swift_name("encodeLong(value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNotNullMark __attribute__((swift_name("encodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNull __attribute__((swift_name("encodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableValueSerializer:(id<MDTMKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableValue(serializer:value:)")));
- (void)encodeSerializableValueSerializer:(id<MDTMKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableValue(serializer:value:)")));
- (void)encodeShortValue:(int16_t)value __attribute__((swift_name("encodeShort(value:)")));
- (void)encodeStringValue:(NSString *)value __attribute__((swift_name("encodeString(value:)")));
@property (readonly) MDTMKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialDescriptor")))
@protocol MDTMKotlinx_serialization_coreSerialDescriptor
@required
- (NSArray<id<MDTMKotlinAnnotation>> *)getElementAnnotationsIndex:(int32_t)index __attribute__((swift_name("getElementAnnotations(index:)")));
- (id<MDTMKotlinx_serialization_coreSerialDescriptor>)getElementDescriptorIndex:(int32_t)index __attribute__((swift_name("getElementDescriptor(index:)")));
- (int32_t)getElementIndexName:(NSString *)name __attribute__((swift_name("getElementIndex(name:)")));
- (NSString *)getElementNameIndex:(int32_t)index __attribute__((swift_name("getElementName(index:)")));
- (BOOL)isElementOptionalIndex:(int32_t)index __attribute__((swift_name("isElementOptional(index:)")));
@property (readonly) NSArray<id<MDTMKotlinAnnotation>> *annotations __attribute__((swift_name("annotations")));
@property (readonly) int32_t elementsCount __attribute__((swift_name("elementsCount")));
@property (readonly) BOOL isInline __attribute__((swift_name("isInline")));
@property (readonly) BOOL isNullable __attribute__((swift_name("isNullable")));
@property (readonly) MDTMKotlinx_serialization_coreSerialKind *kind __attribute__((swift_name("kind")));
@property (readonly) NSString *serialName __attribute__((swift_name("serialName")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreDecoder")))
@protocol MDTMKotlinx_serialization_coreDecoder
@required
- (id<MDTMKotlinx_serialization_coreCompositeDecoder>)beginStructureDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));
- (BOOL)decodeBoolean __attribute__((swift_name("decodeBoolean()")));
- (int8_t)decodeByte __attribute__((swift_name("decodeByte()")));
- (unichar)decodeChar __attribute__((swift_name("decodeChar()")));
- (double)decodeDouble __attribute__((swift_name("decodeDouble()")));
- (int32_t)decodeEnumEnumDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)enumDescriptor __attribute__((swift_name("decodeEnum(enumDescriptor:)")));
- (float)decodeFloat __attribute__((swift_name("decodeFloat()")));
- (id<MDTMKotlinx_serialization_coreDecoder>)decodeInlineDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeInline(descriptor:)")));
- (int32_t)decodeInt __attribute__((swift_name("decodeInt()")));
- (int64_t)decodeLong __attribute__((swift_name("decodeLong()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeNotNullMark __attribute__((swift_name("decodeNotNullMark()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (MDTMKotlinNothing * _Nullable)decodeNull __attribute__((swift_name("decodeNull()")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableValueDeserializer:(id<MDTMKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeNullableSerializableValue(deserializer:)")));
- (id _Nullable)decodeSerializableValueDeserializer:(id<MDTMKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeSerializableValue(deserializer:)")));
- (int16_t)decodeShort __attribute__((swift_name("decodeShort()")));
- (NSString *)decodeString __attribute__((swift_name("decodeString()")));
@property (readonly) MDTMKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_serialization_jsonJsonElement.Companion")))
@interface MDTMKotlinx_serialization_jsonJsonElementCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKotlinx_serialization_jsonJsonElementCompanion *shared __attribute__((swift_name("shared")));
- (id<MDTMKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((swift_name("KotlinByteIterator")))
@interface MDTMKotlinByteIterator : MDTMBase <MDTMKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (MDTMByte *)next __attribute__((swift_name("next()")));
- (int8_t)nextByte __attribute__((swift_name("nextByte()")));
@end

__attribute__((swift_name("KotlinKType")))
@protocol MDTMKotlinKType
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
@property (readonly) NSArray<MDTMKotlinKTypeProjection *> *arguments __attribute__((swift_name("arguments")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
@property (readonly) id<MDTMKotlinKClassifier> _Nullable classifier __attribute__((swift_name("classifier")));
@property (readonly) BOOL isMarkedNullable __attribute__((swift_name("isMarkedNullable")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpUrl.Companion")))
@interface MDTMKtor_httpUrlCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_httpUrlCompanion *shared __attribute__((swift_name("shared")));
- (id<MDTMKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLProtocol")))
@interface MDTMKtor_httpURLProtocol : MDTMBase <MDTMKtor_ioJvmSerializable>
- (instancetype)initWithName:(NSString *)name defaultPort:(int32_t)defaultPort __attribute__((swift_name("init(name:defaultPort:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMKtor_httpURLProtocolCompanion *companion __attribute__((swift_name("companion")));
- (MDTMKtor_httpURLProtocol *)doCopyName:(NSString *)name defaultPort:(int32_t)defaultPort __attribute__((swift_name("doCopy(name:defaultPort:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t defaultPort __attribute__((swift_name("defaultPort")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsDelegatingConversionServiceConfiguration")))
@interface MDTMKtor_utilsDelegatingConversionServiceConfiguration<T> : MDTMBase
- (void)decodeConverter:(T (^)(NSArray<NSString *> *))converter __attribute__((swift_name("decode(converter:)")));
- (void)encodeConverter:(NSArray<NSString *> *(^)(T))converter __attribute__((swift_name("encode(converter:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLBuilder.Companion")))
@interface MDTMKtor_httpURLBuilderCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_httpURLBuilderCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("Ktor_httpParametersBuilder")))
@protocol MDTMKtor_httpParametersBuilder <MDTMKtor_utilsStringValuesBuilder>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_ioCharset.Companion")))
@interface MDTMKtor_ioCharsetCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_ioCharsetCompanion *shared __attribute__((swift_name("shared")));
- (MDTMKtor_ioCharset *)forNameName:(NSString *)name __attribute__((swift_name("forName(name:)")));
- (BOOL)isSupportedCharset:(NSString *)charset __attribute__((swift_name("isSupported(charset:)")));
@end

__attribute__((swift_name("Ktor_ioCharsetDecoder")))
@interface MDTMKtor_ioCharsetDecoder : MDTMBase
- (instancetype)initWith_charset:(MDTMKtor_ioCharset *)_charset __attribute__((swift_name("init(_charset:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("Ktor_ioCharsetEncoder")))
@interface MDTMKtor_ioCharsetEncoder : MDTMBase
- (instancetype)initWith_charset:(MDTMKtor_ioCharset *)_charset __attribute__((swift_name("init(_charset:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsWeekDay")))
@interface MDTMKtor_utilsWeekDay : MDTMKotlinEnum<MDTMKtor_utilsWeekDay *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) MDTMKtor_utilsWeekDayCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) MDTMKtor_utilsWeekDay *monday __attribute__((swift_name("monday")));
@property (class, readonly) MDTMKtor_utilsWeekDay *tuesday __attribute__((swift_name("tuesday")));
@property (class, readonly) MDTMKtor_utilsWeekDay *wednesday __attribute__((swift_name("wednesday")));
@property (class, readonly) MDTMKtor_utilsWeekDay *thursday __attribute__((swift_name("thursday")));
@property (class, readonly) MDTMKtor_utilsWeekDay *friday __attribute__((swift_name("friday")));
@property (class, readonly) MDTMKtor_utilsWeekDay *saturday __attribute__((swift_name("saturday")));
@property (class, readonly) MDTMKtor_utilsWeekDay *sunday __attribute__((swift_name("sunday")));
+ (MDTMKotlinArray<MDTMKtor_utilsWeekDay *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<MDTMKtor_utilsWeekDay *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsMonth")))
@interface MDTMKtor_utilsMonth : MDTMKotlinEnum<MDTMKtor_utilsMonth *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) MDTMKtor_utilsMonthCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) MDTMKtor_utilsMonth *january __attribute__((swift_name("january")));
@property (class, readonly) MDTMKtor_utilsMonth *february __attribute__((swift_name("february")));
@property (class, readonly) MDTMKtor_utilsMonth *march __attribute__((swift_name("march")));
@property (class, readonly) MDTMKtor_utilsMonth *april __attribute__((swift_name("april")));
@property (class, readonly) MDTMKtor_utilsMonth *may __attribute__((swift_name("may")));
@property (class, readonly) MDTMKtor_utilsMonth *june __attribute__((swift_name("june")));
@property (class, readonly) MDTMKtor_utilsMonth *july __attribute__((swift_name("july")));
@property (class, readonly) MDTMKtor_utilsMonth *august __attribute__((swift_name("august")));
@property (class, readonly) MDTMKtor_utilsMonth *september __attribute__((swift_name("september")));
@property (class, readonly) MDTMKtor_utilsMonth *october __attribute__((swift_name("october")));
@property (class, readonly) MDTMKtor_utilsMonth *november __attribute__((swift_name("november")));
@property (class, readonly) MDTMKtor_utilsMonth *december __attribute__((swift_name("december")));
+ (MDTMKotlinArray<MDTMKtor_utilsMonth *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<MDTMKtor_utilsMonth *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsGMTDate.Companion")))
@interface MDTMKtor_utilsGMTDateCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_utilsGMTDateCompanion *shared __attribute__((swift_name("shared")));
- (id<MDTMKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@property (readonly) MDTMKtor_utilsGMTDate *START __attribute__((swift_name("START")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpStatusCode.Companion")))
@interface MDTMKtor_httpHttpStatusCodeCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_httpHttpStatusCodeCompanion *shared __attribute__((swift_name("shared")));
- (MDTMKtor_httpHttpStatusCode *)fromValueValue:(int32_t)value __attribute__((swift_name("fromValue(value:)")));
@property (readonly) MDTMKtor_httpHttpStatusCode *Accepted __attribute__((swift_name("Accepted")));
@property (readonly) MDTMKtor_httpHttpStatusCode *BadGateway __attribute__((swift_name("BadGateway")));
@property (readonly) MDTMKtor_httpHttpStatusCode *BadRequest __attribute__((swift_name("BadRequest")));
@property (readonly) MDTMKtor_httpHttpStatusCode *Conflict __attribute__((swift_name("Conflict")));
@property (readonly) MDTMKtor_httpHttpStatusCode *Continue __attribute__((swift_name("Continue")));
@property (readonly) MDTMKtor_httpHttpStatusCode *Created __attribute__((swift_name("Created")));
@property (readonly) MDTMKtor_httpHttpStatusCode *ExpectationFailed __attribute__((swift_name("ExpectationFailed")));
@property (readonly) MDTMKtor_httpHttpStatusCode *FailedDependency __attribute__((swift_name("FailedDependency")));
@property (readonly) MDTMKtor_httpHttpStatusCode *Forbidden __attribute__((swift_name("Forbidden")));
@property (readonly) MDTMKtor_httpHttpStatusCode *Found __attribute__((swift_name("Found")));
@property (readonly) MDTMKtor_httpHttpStatusCode *GatewayTimeout __attribute__((swift_name("GatewayTimeout")));
@property (readonly) MDTMKtor_httpHttpStatusCode *Gone __attribute__((swift_name("Gone")));
@property (readonly) MDTMKtor_httpHttpStatusCode *InsufficientStorage __attribute__((swift_name("InsufficientStorage")));
@property (readonly) MDTMKtor_httpHttpStatusCode *InternalServerError __attribute__((swift_name("InternalServerError")));
@property (readonly) MDTMKtor_httpHttpStatusCode *LengthRequired __attribute__((swift_name("LengthRequired")));
@property (readonly) MDTMKtor_httpHttpStatusCode *Locked __attribute__((swift_name("Locked")));
@property (readonly) MDTMKtor_httpHttpStatusCode *MethodNotAllowed __attribute__((swift_name("MethodNotAllowed")));
@property (readonly) MDTMKtor_httpHttpStatusCode *MovedPermanently __attribute__((swift_name("MovedPermanently")));
@property (readonly) MDTMKtor_httpHttpStatusCode *MultiStatus __attribute__((swift_name("MultiStatus")));
@property (readonly) MDTMKtor_httpHttpStatusCode *MultipleChoices __attribute__((swift_name("MultipleChoices")));
@property (readonly) MDTMKtor_httpHttpStatusCode *NoContent __attribute__((swift_name("NoContent")));
@property (readonly) MDTMKtor_httpHttpStatusCode *NonAuthoritativeInformation __attribute__((swift_name("NonAuthoritativeInformation")));
@property (readonly) MDTMKtor_httpHttpStatusCode *NotAcceptable __attribute__((swift_name("NotAcceptable")));
@property (readonly) MDTMKtor_httpHttpStatusCode *NotFound __attribute__((swift_name("NotFound")));
@property (readonly) MDTMKtor_httpHttpStatusCode *NotImplemented __attribute__((swift_name("NotImplemented")));
@property (readonly) MDTMKtor_httpHttpStatusCode *NotModified __attribute__((swift_name("NotModified")));
@property (readonly) MDTMKtor_httpHttpStatusCode *OK __attribute__((swift_name("OK")));
@property (readonly) MDTMKtor_httpHttpStatusCode *PartialContent __attribute__((swift_name("PartialContent")));
@property (readonly) MDTMKtor_httpHttpStatusCode *PayloadTooLarge __attribute__((swift_name("PayloadTooLarge")));
@property (readonly) MDTMKtor_httpHttpStatusCode *PaymentRequired __attribute__((swift_name("PaymentRequired")));
@property (readonly) MDTMKtor_httpHttpStatusCode *PermanentRedirect __attribute__((swift_name("PermanentRedirect")));
@property (readonly) MDTMKtor_httpHttpStatusCode *PreconditionFailed __attribute__((swift_name("PreconditionFailed")));
@property (readonly) MDTMKtor_httpHttpStatusCode *Processing __attribute__((swift_name("Processing")));
@property (readonly) MDTMKtor_httpHttpStatusCode *ProxyAuthenticationRequired __attribute__((swift_name("ProxyAuthenticationRequired")));
@property (readonly) MDTMKtor_httpHttpStatusCode *RequestHeaderFieldTooLarge __attribute__((swift_name("RequestHeaderFieldTooLarge")));
@property (readonly) MDTMKtor_httpHttpStatusCode *RequestTimeout __attribute__((swift_name("RequestTimeout")));
@property (readonly) MDTMKtor_httpHttpStatusCode *RequestURITooLong __attribute__((swift_name("RequestURITooLong")));
@property (readonly) MDTMKtor_httpHttpStatusCode *RequestedRangeNotSatisfiable __attribute__((swift_name("RequestedRangeNotSatisfiable")));
@property (readonly) MDTMKtor_httpHttpStatusCode *ResetContent __attribute__((swift_name("ResetContent")));
@property (readonly) MDTMKtor_httpHttpStatusCode *SeeOther __attribute__((swift_name("SeeOther")));
@property (readonly) MDTMKtor_httpHttpStatusCode *ServiceUnavailable __attribute__((swift_name("ServiceUnavailable")));
@property (readonly) MDTMKtor_httpHttpStatusCode *SwitchProxy __attribute__((swift_name("SwitchProxy")));
@property (readonly) MDTMKtor_httpHttpStatusCode *SwitchingProtocols __attribute__((swift_name("SwitchingProtocols")));
@property (readonly) MDTMKtor_httpHttpStatusCode *TemporaryRedirect __attribute__((swift_name("TemporaryRedirect")));
@property (readonly) MDTMKtor_httpHttpStatusCode *TooEarly __attribute__((swift_name("TooEarly")));
@property (readonly) MDTMKtor_httpHttpStatusCode *TooManyRequests __attribute__((swift_name("TooManyRequests")));
@property (readonly) MDTMKtor_httpHttpStatusCode *Unauthorized __attribute__((swift_name("Unauthorized")));
@property (readonly) MDTMKtor_httpHttpStatusCode *UnprocessableEntity __attribute__((swift_name("UnprocessableEntity")));
@property (readonly) MDTMKtor_httpHttpStatusCode *UnsupportedMediaType __attribute__((swift_name("UnsupportedMediaType")));
@property (readonly) MDTMKtor_httpHttpStatusCode *UpgradeRequired __attribute__((swift_name("UpgradeRequired")));
@property (readonly) MDTMKtor_httpHttpStatusCode *UseProxy __attribute__((swift_name("UseProxy")));
@property (readonly) MDTMKtor_httpHttpStatusCode *VariantAlsoNegotiates __attribute__((swift_name("VariantAlsoNegotiates")));
@property (readonly) MDTMKtor_httpHttpStatusCode *VersionNotSupported __attribute__((swift_name("VersionNotSupported")));
@property (readonly) NSArray<MDTMKtor_httpHttpStatusCode *> *allStatusCodes __attribute__((swift_name("allStatusCodes")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpProtocolVersion.Companion")))
@interface MDTMKtor_httpHttpProtocolVersionCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_httpHttpProtocolVersionCompanion *shared __attribute__((swift_name("shared")));
- (MDTMKtor_httpHttpProtocolVersion *)fromValueName:(NSString *)name major:(int32_t)major minor:(int32_t)minor __attribute__((swift_name("fromValue(name:major:minor:)")));
- (MDTMKtor_httpHttpProtocolVersion *)parseValue:(id)value __attribute__((swift_name("parse(value:)")));
@property (readonly) MDTMKtor_httpHttpProtocolVersion *HTTP_1_0 __attribute__((swift_name("HTTP_1_0")));
@property (readonly) MDTMKtor_httpHttpProtocolVersion *HTTP_1_1 __attribute__((swift_name("HTTP_1_1")));
@property (readonly) MDTMKtor_httpHttpProtocolVersion *HTTP_2_0 __attribute__((swift_name("HTTP_2_0")));
@property (readonly) MDTMKtor_httpHttpProtocolVersion *QUIC __attribute__((swift_name("QUIC")));
@property (readonly) MDTMKtor_httpHttpProtocolVersion *SPDY_3 __attribute__((swift_name("SPDY_3")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHeaderValueParam")))
@interface MDTMKtor_httpHeaderValueParam : MDTMBase
- (instancetype)initWithName:(NSString *)name value:(NSString *)value __attribute__((swift_name("init(name:value:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithName:(NSString *)name value:(NSString *)value escapeValue:(BOOL)escapeValue __attribute__((swift_name("init(name:value:escapeValue:)"))) __attribute__((objc_designated_initializer));
- (MDTMKtor_httpHeaderValueParam *)doCopyName:(NSString *)name value:(NSString *)value escapeValue:(BOOL)escapeValue __attribute__((swift_name("doCopy(name:value:escapeValue:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL escapeValue __attribute__((swift_name("escapeValue")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) NSString *value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHeaderValueWithParameters.Companion")))
@interface MDTMKtor_httpHeaderValueWithParametersCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_httpHeaderValueWithParametersCompanion *shared __attribute__((swift_name("shared")));
- (id _Nullable)parseValue:(NSString *)value init:(id _Nullable (^)(NSString *, NSArray<MDTMKtor_httpHeaderValueParam *> *))init __attribute__((swift_name("parse(value:init:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpContentType.Companion")))
@interface MDTMKtor_httpContentTypeCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_httpContentTypeCompanion *shared __attribute__((swift_name("shared")));
- (MDTMKtor_httpContentType *)parseValue:(NSString *)value __attribute__((swift_name("parse(value:)")));
@property (readonly) MDTMKtor_httpContentType *Any __attribute__((swift_name("Any")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_websocketsFrame.Companion")))
@interface MDTMKtor_websocketsFrameCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_websocketsFrameCompanion *shared __attribute__((swift_name("shared")));
- (MDTMKtor_websocketsFrame *)byTypeFin:(BOOL)fin frameType:(MDTMKtor_websocketsFrameType *)frameType data:(MDTMKotlinByteArray *)data rsv1:(BOOL)rsv1 rsv2:(BOOL)rsv2 rsv3:(BOOL)rsv3 __attribute__((swift_name("byType(fin:frameType:data:rsv1:rsv2:rsv3:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_websocketsFrameType")))
@interface MDTMKtor_websocketsFrameType : MDTMKotlinEnum<MDTMKtor_websocketsFrameType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) MDTMKtor_websocketsFrameTypeCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) MDTMKtor_websocketsFrameType *text __attribute__((swift_name("text")));
@property (class, readonly) MDTMKtor_websocketsFrameType *binary __attribute__((swift_name("binary")));
@property (class, readonly) MDTMKtor_websocketsFrameType *close __attribute__((swift_name("close")));
@property (class, readonly) MDTMKtor_websocketsFrameType *ping __attribute__((swift_name("ping")));
@property (class, readonly) MDTMKtor_websocketsFrameType *pong __attribute__((swift_name("pong")));
+ (MDTMKotlinArray<MDTMKtor_websocketsFrameType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<MDTMKtor_websocketsFrameType *> *entries __attribute__((swift_name("entries")));
@property (readonly) BOOL controlFrame __attribute__((swift_name("controlFrame")));
@property (readonly) int32_t opcode __attribute__((swift_name("opcode")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_websocketsWebSocketExtensionHeader")))
@interface MDTMKtor_websocketsWebSocketExtensionHeader : MDTMBase
- (instancetype)initWithName:(NSString *)name parameters:(NSArray<NSString *> *)parameters __attribute__((swift_name("init(name:parameters:)"))) __attribute__((objc_designated_initializer));
- (id<MDTMKotlinSequence>)parseParameters __attribute__((swift_name("parseParameters()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) NSArray<NSString *> *parameters __attribute__((swift_name("parameters")));
@end

__attribute__((swift_name("Ktor_websocketsWebSocketExtensionFactory")))
@protocol MDTMKtor_websocketsWebSocketExtensionFactory
@required
- (id<MDTMKtor_websocketsWebSocketExtension>)installConfig:(void (^)(id))config __attribute__((swift_name("install(config:)")));
@property (readonly) MDTMKtor_utilsAttributeKey<id<MDTMKtor_websocketsWebSocketExtension>> *key __attribute__((swift_name("key")));
@property (readonly) BOOL rsv1 __attribute__((swift_name("rsv1")));
@property (readonly) BOOL rsv2 __attribute__((swift_name("rsv2")));
@property (readonly) BOOL rsv3 __attribute__((swift_name("rsv3")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpHttpMethod.Companion")))
@interface MDTMKtor_httpHttpMethodCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_httpHttpMethodCompanion *shared __attribute__((swift_name("shared")));
- (MDTMKtor_httpHttpMethod *)parseMethod:(NSString *)method __attribute__((swift_name("parse(method:)")));
@property (readonly) NSArray<MDTMKtor_httpHttpMethod *> *DefaultMethods __attribute__((swift_name("DefaultMethods")));
@property (readonly) MDTMKtor_httpHttpMethod *Delete __attribute__((swift_name("Delete")));
@property (readonly) MDTMKtor_httpHttpMethod *Get __attribute__((swift_name("Get")));
@property (readonly) MDTMKtor_httpHttpMethod *Head __attribute__((swift_name("Head")));
@property (readonly) MDTMKtor_httpHttpMethod *Options __attribute__((swift_name("Options")));
@property (readonly) MDTMKtor_httpHttpMethod *Patch __attribute__((swift_name("Patch")));
@property (readonly) MDTMKtor_httpHttpMethod *Post __attribute__((swift_name("Post")));
@property (readonly) MDTMKtor_httpHttpMethod *Put __attribute__((swift_name("Put")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Kotlinx_io_coreBuffer")))
@interface MDTMKotlinx_io_coreBuffer : MDTMBase <MDTMKotlinx_io_coreSource, MDTMKotlinx_io_coreSink>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)clear __attribute__((swift_name("clear()")));
- (void)close __attribute__((swift_name("close()")));
- (MDTMKotlinx_io_coreBuffer *)doCopy __attribute__((swift_name("doCopy()")));
- (void)doCopyToOut:(MDTMKotlinx_io_coreBuffer *)out startIndex:(int64_t)startIndex endIndex:(int64_t)endIndex __attribute__((swift_name("doCopyTo(out:startIndex:endIndex:)")));
- (void)emit __attribute__((swift_name("emit()")));
- (BOOL)exhausted __attribute__((swift_name("exhausted()")));
- (void)flush __attribute__((swift_name("flush()")));
- (int8_t)getPosition:(int64_t)position __attribute__((swift_name("get(position:)")));

/**
 * @note annotations
 *   kotlinx.io.InternalIoApi
*/
- (void)hintEmit __attribute__((swift_name("hintEmit()")));
- (id<MDTMKotlinx_io_coreSource>)peek __attribute__((swift_name("peek()")));
- (int64_t)readAtMostToSink:(MDTMKotlinx_io_coreBuffer *)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readAtMostTo(sink:byteCount:)")));
- (int32_t)readAtMostToSink:(MDTMKotlinByteArray *)sink startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("readAtMostTo(sink:startIndex:endIndex:)")));
- (int8_t)readByte __attribute__((swift_name("readByte()")));
- (int32_t)readInt __attribute__((swift_name("readInt()")));
- (int64_t)readLong __attribute__((swift_name("readLong()")));
- (int16_t)readShort __attribute__((swift_name("readShort()")));
- (void)readToSink:(id<MDTMKotlinx_io_coreRawSink>)sink byteCount:(int64_t)byteCount __attribute__((swift_name("readTo(sink:byteCount:)")));
- (BOOL)requestByteCount:(int64_t)byteCount __attribute__((swift_name("request(byteCount:)")));
- (void)requireByteCount:(int64_t)byteCount __attribute__((swift_name("require(byteCount:)")));
- (void)skipByteCount:(int64_t)byteCount __attribute__((swift_name("skip(byteCount:)")));
- (NSString *)description __attribute__((swift_name("description()")));
- (int64_t)transferFromSource:(id<MDTMKotlinx_io_coreRawSource>)source __attribute__((swift_name("transferFrom(source:)")));
- (int64_t)transferToSink:(id<MDTMKotlinx_io_coreRawSink>)sink __attribute__((swift_name("transferTo(sink:)")));
- (void)writeSource:(MDTMKotlinx_io_coreBuffer *)source byteCount_:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount_:)")));
- (void)writeSource:(id<MDTMKotlinx_io_coreRawSource>)source byteCount:(int64_t)byteCount __attribute__((swift_name("write(source:byteCount:)")));
- (void)writeSource:(MDTMKotlinByteArray *)source startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("write(source:startIndex:endIndex:)")));
- (void)writeByteByte:(int8_t)byte __attribute__((swift_name("writeByte(byte:)")));
- (void)writeIntInt:(int32_t)int_ __attribute__((swift_name("writeInt(int:)")));
- (void)writeLongLong:(int64_t)long_ __attribute__((swift_name("writeLong(long:)")));
- (void)writeShortShort:(int16_t)short_ __attribute__((swift_name("writeShort(short:)")));

/**
 * @note annotations
 *   kotlinx.io.InternalIoApi
*/
@property (readonly) MDTMKotlinx_io_coreBuffer *buffer __attribute__((swift_name("buffer")));
@property (readonly) int64_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpContentDisposition")))
@interface MDTMKtor_httpContentDisposition : MDTMKtor_httpHeaderValueWithParameters
- (instancetype)initWithDisposition:(NSString *)disposition parameters:(NSArray<MDTMKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(disposition:parameters:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithContent:(NSString *)content parameters:(NSArray<MDTMKtor_httpHeaderValueParam *> *)parameters __attribute__((swift_name("init(content:parameters:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) MDTMKtor_httpContentDispositionCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (MDTMKtor_httpContentDisposition *)withParameterKey:(NSString *)key value:(NSString *)value encodeValue:(BOOL)encodeValue __attribute__((swift_name("withParameter(key:value:encodeValue:)")));
- (MDTMKtor_httpContentDisposition *)withParametersNewParameters:(NSArray<MDTMKtor_httpHeaderValueParam *> *)newParameters __attribute__((swift_name("withParameters(newParameters:)")));
@property (readonly) NSString *disposition __attribute__((swift_name("disposition")));
@property (readonly) NSString * _Nullable name __attribute__((swift_name("name")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeEncoder")))
@protocol MDTMKotlinx_serialization_coreCompositeEncoder
@required
- (void)encodeBooleanElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(BOOL)value __attribute__((swift_name("encodeBooleanElement(descriptor:index:value:)")));
- (void)encodeByteElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int8_t)value __attribute__((swift_name("encodeByteElement(descriptor:index:value:)")));
- (void)encodeCharElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(unichar)value __attribute__((swift_name("encodeCharElement(descriptor:index:value:)")));
- (void)encodeDoubleElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(double)value __attribute__((swift_name("encodeDoubleElement(descriptor:index:value:)")));
- (void)encodeFloatElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(float)value __attribute__((swift_name("encodeFloatElement(descriptor:index:value:)")));
- (id<MDTMKotlinx_serialization_coreEncoder>)encodeInlineElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("encodeInlineElement(descriptor:index:)")));
- (void)encodeIntElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int32_t)value __attribute__((swift_name("encodeIntElement(descriptor:index:value:)")));
- (void)encodeLongElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int64_t)value __attribute__((swift_name("encodeLongElement(descriptor:index:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<MDTMKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeSerializableElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<MDTMKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableElement(descriptor:index:serializer:value:)")));
- (void)encodeShortElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int16_t)value __attribute__((swift_name("encodeShortElement(descriptor:index:value:)")));
- (void)encodeStringElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(NSString *)value __attribute__((swift_name("encodeStringElement(descriptor:index:value:)")));
- (void)endStructureDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)shouldEncodeElementDefaultDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("shouldEncodeElementDefault(descriptor:index:)")));
@property (readonly) MDTMKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerializersModule")))
@interface MDTMKotlinx_serialization_coreSerializersModule : MDTMBase

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)dumpToCollector:(id<MDTMKotlinx_serialization_coreSerializersModuleCollector>)collector __attribute__((swift_name("dumpTo(collector:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<MDTMKotlinx_serialization_coreKSerializer> _Nullable)getContextualKClass:(id<MDTMKotlinKClass>)kClass typeArgumentsSerializers:(NSArray<id<MDTMKotlinx_serialization_coreKSerializer>> *)typeArgumentsSerializers __attribute__((swift_name("getContextual(kClass:typeArgumentsSerializers:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<MDTMKotlinx_serialization_coreSerializationStrategy> _Nullable)getPolymorphicBaseClass:(id<MDTMKotlinKClass>)baseClass value:(id)value __attribute__((swift_name("getPolymorphic(baseClass:value:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<MDTMKotlinx_serialization_coreDeserializationStrategy> _Nullable)getPolymorphicBaseClass:(id<MDTMKotlinKClass>)baseClass serializedClassName:(NSString * _Nullable)serializedClassName __attribute__((swift_name("getPolymorphic(baseClass:serializedClassName:)")));
@end

__attribute__((swift_name("KotlinAnnotation")))
@protocol MDTMKotlinAnnotation
@required
@end

__attribute__((swift_name("Kotlinx_serialization_coreSerialKind")))
@interface MDTMKotlinx_serialization_coreSerialKind : MDTMBase
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Kotlinx_serialization_coreCompositeDecoder")))
@protocol MDTMKotlinx_serialization_coreCompositeDecoder
@required
- (BOOL)decodeBooleanElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeBooleanElement(descriptor:index:)")));
- (int8_t)decodeByteElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeByteElement(descriptor:index:)")));
- (unichar)decodeCharElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeCharElement(descriptor:index:)")));
- (int32_t)decodeCollectionSizeDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeCollectionSize(descriptor:)")));
- (double)decodeDoubleElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeDoubleElement(descriptor:index:)")));
- (int32_t)decodeElementIndexDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeElementIndex(descriptor:)")));
- (float)decodeFloatElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeFloatElement(descriptor:index:)")));
- (id<MDTMKotlinx_serialization_coreDecoder>)decodeInlineElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeInlineElement(descriptor:index:)")));
- (int32_t)decodeIntElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeIntElement(descriptor:index:)")));
- (int64_t)decodeLongElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeLongElement(descriptor:index:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<MDTMKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeNullableSerializableElement(descriptor:index:deserializer:previousValue:)")));

/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeSequentially __attribute__((swift_name("decodeSequentially()")));
- (id _Nullable)decodeSerializableElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<MDTMKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeSerializableElement(descriptor:index:deserializer:previousValue:)")));
- (int16_t)decodeShortElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeShortElement(descriptor:index:)")));
- (NSString *)decodeStringElementDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeStringElement(descriptor:index:)")));
- (void)endStructureDescriptor:(id<MDTMKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));
@property (readonly) MDTMKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKTypeProjection")))
@interface MDTMKotlinKTypeProjection : MDTMBase
- (instancetype)initWithVariance:(MDTMKotlinKVariance * _Nullable)variance type:(id<MDTMKotlinKType> _Nullable)type __attribute__((swift_name("init(variance:type:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) MDTMKotlinKTypeProjectionCompanion *companion __attribute__((swift_name("companion")));
- (MDTMKotlinKTypeProjection *)doCopyVariance:(MDTMKotlinKVariance * _Nullable)variance type:(id<MDTMKotlinKType> _Nullable)type __attribute__((swift_name("doCopy(variance:type:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<MDTMKotlinKType> _Nullable type __attribute__((swift_name("type")));
@property (readonly) MDTMKotlinKVariance * _Nullable variance __attribute__((swift_name("variance")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpURLProtocol.Companion")))
@interface MDTMKtor_httpURLProtocolCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_httpURLProtocolCompanion *shared __attribute__((swift_name("shared")));
- (MDTMKtor_httpURLProtocol *)createOrDefaultName:(NSString *)name __attribute__((swift_name("createOrDefault(name:)")));
@property (readonly) MDTMKtor_httpURLProtocol *HTTP __attribute__((swift_name("HTTP")));
@property (readonly) MDTMKtor_httpURLProtocol *HTTPS __attribute__((swift_name("HTTPS")));
@property (readonly) MDTMKtor_httpURLProtocol *SOCKS __attribute__((swift_name("SOCKS")));
@property (readonly) MDTMKtor_httpURLProtocol *WS __attribute__((swift_name("WS")));
@property (readonly) MDTMKtor_httpURLProtocol *WSS __attribute__((swift_name("WSS")));
@property (readonly) NSDictionary<NSString *, MDTMKtor_httpURLProtocol *> *byName __attribute__((swift_name("byName")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsWeekDay.Companion")))
@interface MDTMKtor_utilsWeekDayCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_utilsWeekDayCompanion *shared __attribute__((swift_name("shared")));
- (MDTMKtor_utilsWeekDay *)fromOrdinal:(int32_t)ordinal __attribute__((swift_name("from(ordinal:)")));
- (MDTMKtor_utilsWeekDay *)fromValue:(NSString *)value __attribute__((swift_name("from(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_utilsMonth.Companion")))
@interface MDTMKtor_utilsMonthCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_utilsMonthCompanion *shared __attribute__((swift_name("shared")));
- (MDTMKtor_utilsMonth *)fromOrdinal:(int32_t)ordinal __attribute__((swift_name("from(ordinal:)")));
- (MDTMKtor_utilsMonth *)fromValue:(NSString *)value __attribute__((swift_name("from(value:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_websocketsFrameType.Companion")))
@interface MDTMKtor_websocketsFrameTypeCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_websocketsFrameTypeCompanion *shared __attribute__((swift_name("shared")));
- (MDTMKtor_websocketsFrameType * _Nullable)getOpcode:(int32_t)opcode __attribute__((swift_name("get(opcode:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ktor_httpContentDisposition.Companion")))
@interface MDTMKtor_httpContentDispositionCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKtor_httpContentDispositionCompanion *shared __attribute__((swift_name("shared")));
- (MDTMKtor_httpContentDisposition *)parseValue:(NSString *)value __attribute__((swift_name("parse(value:)")));
@property (readonly) MDTMKtor_httpContentDisposition *Attachment __attribute__((swift_name("Attachment")));
@property (readonly) MDTMKtor_httpContentDisposition *File __attribute__((swift_name("File")));
@property (readonly) MDTMKtor_httpContentDisposition *Inline __attribute__((swift_name("Inline")));
@property (readonly) MDTMKtor_httpContentDisposition *Mixed __attribute__((swift_name("Mixed")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerializersModuleCollector")))
@protocol MDTMKotlinx_serialization_coreSerializersModuleCollector
@required
- (void)contextualKClass:(id<MDTMKotlinKClass>)kClass provider:(id<MDTMKotlinx_serialization_coreKSerializer> (^)(NSArray<id<MDTMKotlinx_serialization_coreKSerializer>> *))provider __attribute__((swift_name("contextual(kClass:provider:)")));
- (void)contextualKClass:(id<MDTMKotlinKClass>)kClass serializer:(id<MDTMKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("contextual(kClass:serializer:)")));
- (void)polymorphicBaseClass:(id<MDTMKotlinKClass>)baseClass actualClass:(id<MDTMKotlinKClass>)actualClass actualSerializer:(id<MDTMKotlinx_serialization_coreKSerializer>)actualSerializer __attribute__((swift_name("polymorphic(baseClass:actualClass:actualSerializer:)")));
- (void)polymorphicDefaultBaseClass:(id<MDTMKotlinKClass>)baseClass defaultDeserializerProvider:(id<MDTMKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefault(baseClass:defaultDeserializerProvider:)"))) __attribute__((deprecated("Deprecated in favor of function with more precise name: polymorphicDefaultDeserializer")));
- (void)polymorphicDefaultDeserializerBaseClass:(id<MDTMKotlinKClass>)baseClass defaultDeserializerProvider:(id<MDTMKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefaultDeserializer(baseClass:defaultDeserializerProvider:)")));
- (void)polymorphicDefaultSerializerBaseClass:(id<MDTMKotlinKClass>)baseClass defaultSerializerProvider:(id<MDTMKotlinx_serialization_coreSerializationStrategy> _Nullable (^)(id))defaultSerializerProvider __attribute__((swift_name("polymorphicDefaultSerializer(baseClass:defaultSerializerProvider:)")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKVariance")))
@interface MDTMKotlinKVariance : MDTMKotlinEnum<MDTMKotlinKVariance *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) MDTMKotlinKVariance *invariant __attribute__((swift_name("invariant")));
@property (class, readonly) MDTMKotlinKVariance *in __attribute__((swift_name("in")));
@property (class, readonly) MDTMKotlinKVariance *out __attribute__((swift_name("out")));
+ (MDTMKotlinArray<MDTMKotlinKVariance *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<MDTMKotlinKVariance *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKTypeProjection.Companion")))
@interface MDTMKotlinKTypeProjectionCompanion : MDTMBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) MDTMKotlinKTypeProjectionCompanion *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (MDTMKotlinKTypeProjection *)contravariantType:(id<MDTMKotlinKType>)type __attribute__((swift_name("contravariant(type:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (MDTMKotlinKTypeProjection *)covariantType:(id<MDTMKotlinKType>)type __attribute__((swift_name("covariant(type:)")));

/**
 * @note annotations
 *   kotlin.jvm.JvmStatic
*/
- (MDTMKotlinKTypeProjection *)invariantType:(id<MDTMKotlinKType>)type __attribute__((swift_name("invariant(type:)")));
@property (readonly) MDTMKotlinKTypeProjection *STAR __attribute__((swift_name("STAR")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
