//
//  Consumer.h
//  mediasoup-client-ios
//
//  Created by Ethan.
//  Copyright © 2019 Ethan. All rights reserved.
//

#ifndef Consumer_h
#define Consumer_h

@class RTCMediaStreamTrack;
@class RTCPeerConnectionFactory;

@interface Consumer : NSObject

-(instancetype)initWithNativeConsumer:(NSValue *)nativeConsumer pcFactory:(RTCPeerConnectionFactory *)pcFactory;

/*! @return Consumer identifier */
-(NSString *)getId;
/*! @return The associated producer identifier */
-(NSString *)getProducerId;
/*! @return Whether the consumer is closed */
-(bool)isClosed;
/*! @return Whether the consumer is paused */
-(bool)isPaused;
/*! @return The media kind (video or audio) */
-(NSString *)getKind;
/*! @return the remote audio or video track */
-(RTCMediaStreamTrack *)getTrack;
/*! @return Consumer RTP parameters */
-(NSString *)getRtpParameters;
/*! @return Custom data object provided by the application in the consumer factory method */
-(NSString *)getAppData;
/*!
    @brief Resumes the consumer
 */
-(void)resume;
/*!
    @brief Pauses the consumer
 */
-(void)pause;
/*! @return Gets the local RTP receiver statistics by calling getStats() in the underlying RTCRtpReceiver instance */
-(NSString *)getStats;
/*!
    @brief Closes the consumer
 */
-(void)close;

@end

@protocol ConsumerListener

/*!
    @brief Executed when the transport this consumer belongs to is closed for whatever reason. The consumer itself is also closed
    @param consumer The consumer instance executing this method
 */
-(void)onTransportClose:(Consumer *)consumer;

@end

#endif /* Consumer_h */
