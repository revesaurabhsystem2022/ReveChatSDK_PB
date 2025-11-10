//
//  VoIPPushHandler.h
//  ReveChatSDK
//
//  Created by reveantivirus on 12/02/25.
//  Copyright © 2025 reve. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PushKit/PushKit.h>


@protocol VoIPPushHandlerDelegate <NSObject>
- (void)didReceiveVoIPPushWithPayload:(PKPushPayload *)payload;
@end

@interface VoIPPushHandler : NSObject <PKPushRegistryDelegate>

@property (nonatomic, weak) id<VoIPPushHandlerDelegate> delegate;

- (void)registerForVoIPPush;

@end
