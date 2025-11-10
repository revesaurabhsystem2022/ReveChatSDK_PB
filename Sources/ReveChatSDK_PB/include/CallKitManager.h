//
//  CallKitManager.h
//  ReveChatSDK
//
//  Created by reveantivirus on 12/02/25.
//  Copyright © 2025 reve. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CallKit/CallKit.h>


@protocol CallKitManagerDelegate <NSObject>
- (void)callDidAnswerWithUUID:(NSUUID *)uuid;
- (void)callDidEndWithUUID:(NSUUID *)uuid;
@end


@interface CallKitManager : NSObject <CXProviderDelegate>

@property (nonatomic, weak) id<CallKitManagerDelegate> delegate;

@property (nonatomic, strong) NSUUID *incomingCallID;
- (void)reportIncomingCallWithUUID:(NSUUID *)uuid handle:(NSString *)handle hasVideo:(BOOL)hasVideo;
- (void)endCallWithUUID:(NSUUID *)uuid;

@end
