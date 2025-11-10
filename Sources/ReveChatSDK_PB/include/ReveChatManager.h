//
//  ReveChatManager.h
//  ReveChatSDK
//
//  Created by Amit on 5/29/17.
//  Copyright © 2017 reve. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
//#import "InitialViewController.h"
#import "ReveChatNavigationController.h"
#import "LoginState.h"
#import "VoIPPushHandler.h"
#import "CallKitManager.h"


#define REVECHATSDK_BUNDLE [NSBundle bundleForClass:[self class]]
#define REVECHATSDK_BUNDLE_LOCALIZE [NSBundle bundleWithURL:[[NSBundle bundleForClass:[self class]] URLForResource:@"SDKResources" withExtension:@"bundle"]]
#define DEBOUNCE_INTERVAL 5.0

typedef NS_ENUM(NSInteger, AppViewController) {
    AppViewControllerPrechat,
    AppViewControllerChat,
    AppViewControllerQueue,
    AppViewControllerOffline,
    AppViewControllerLandingPage
};


@protocol CustomerInterfaceProvider <NSObject>

- (NSString *)getCustomerName;
- (NSString *)getCustomerID;
- (NSString *)getCustomerType;
- (NSString *)getCustomerEmail;
- (NSString *)getCustomerPhone;
- (NSString *)getCustomerAccountID;



@end


@interface ReveChatManager : NSObject <VoIPPushHandlerDelegate, CallKitManagerDelegate>



+(instancetype) sharedManager;

- (void) setupAccountWith:(NSString*)accountId;

- (void)setCustomerProvider:(id<CustomerInterfaceProvider>)provider;
- (NSString *)getCustomerName;
- (NSString *)getCustomerID;
- (NSString *)getCustomerType;
- (NSString *)getCustomerEmail;
- (NSString *)getCustomerPhone;
- (NSString *)getCustomerAccountID;


-(void) initiateReveChatWith:(NSString*)visitorName visitorEmail:(NSString*)visitorEmail visitorMobile:(NSString*)visitorMobile onNavigationViewController:(UINavigationController *)navVC;

-(void) initiateReveChatWith:(NSString*)visitorName visitorEmail:(NSString*)visitorEmail visitorMobile:(NSString*)visitorMobile loginState:(enum LState) loginState onNavigationViewController:(UINavigationController *)navVC;

-(void) initiateReveChatWith:(NSString*)visitorName visitorEmail:(NSString*)visitorEmail visitorMobile:(NSString*)visitorMobile onViewController:(UIViewController *)viewController;

/*customizing methods */

- (void)setThemeColor:(UIColor*)color;


- (void)setBackground:(UIColor*)color;

- (void)setNavigationBarColor:(UIColor*)color;

- (void)setHeaderTintColor:(UIColor*)color;

- (void)setHeaderTextColor:(UIColor*)color;

- (void)setIncomingBubbleColor:(UIColor*)color;

- (void)setOutgoingBubbleColor:(UIColor*)color;

- (void)setInputbarTintColor:(UIColor*)color;

- (void)setInputBarPlaceHolderText:(NSString*)placeholderText;

- (void)setChatTitle:(NSString*)title;

- (void)setDeviceToken:(NSString*)token;

- (BOOL)isOnTopOfNavigationStack:(Class)vcClass;

- (void)setNavBarTitleColor:(UIColor*)color;

- (void)setThemeName:(NSString*)name;

- (void)resume;

/* customizing values */

@property (strong,nonatomic) UIColor* themeColor;

@property (strong,nonatomic) UIColor* backgroundColor;

@property (strong,nonatomic) UIColor* navBarColor;

@property (strong,nonatomic) UIColor* headerTintColor;

@property (strong,nonatomic) UIColor* headerTextColor;

@property (strong,nonatomic) UIColor* incomingBubbleColor;

@property (strong,nonatomic) UIColor* outgoingBubbleColor;

@property (strong,nonatomic) UIColor* inputBarTintColor;

@property (strong,nonatomic) UIColor* navBarTitleColor;

@property (strong,nonatomic) NSString* inputBarPlaceHolderText;

@property (strong,nonatomic) NSString* title;

//@property (strong,nonatomic) NSString* token;


@property (nonatomic, assign) AppViewController currentViewController;

@property (strong,nonatomic) UINavigationController* myRootController;

@property (strong,nonatomic) UIViewController* currrentControllerView;

@property (strong,nonatomic) NSString* queueMessage;
@property (strong,nonatomic) NSString* offlineMessage;
@property (strong,nonatomic) NSString* waitingMessage;
@property (nonatomic,assign) BOOL botTransferred;

@property (nonatomic,assign) enum LState loginState;

@property (nonatomic,assign) BOOL isWebSocketConected;

@property (nonatomic,assign) BOOL isDirectlyLogged;
@property (nonatomic,assign) BOOL isRealServerConnection;

@property (nonatomic,assign) BOOL pushCallAnswered;

@property (nonatomic,assign) BOOL isNormalCall;

@property (strong,nonatomic) NSString* themeName;

@property (strong,nonatomic) ReveChatNavigationController* navCtrl;

@property (strong,nonatomic) UINavigationController *appNavController;


-(UIColor*) getNavBarButtonColor;
- (void)verifyTokenWithCompletion:(void (^)(NSDictionary *responseDict, NSError *error))completion;



@property (strong,nonatomic) NSString* APNSToken;

@property (strong,nonatomic) NSString* VOIPToken;

- (void) connectToServer;


-(void) initiateReveChatCnnectWith:(NSString*)visitorName visitorEmail:(NSString*)visitorEmail visitorMobile:(NSString*)visitorMobile onNavigationViewController:(UINavigationController *)navVC;


-(void) initiateReveChatConnectWith:(NSString*)visitorName visitorEmail:(NSString*)visitorEmail visitorMobile:(NSString*)visitorMobile;


-(void) initiateReveChatWithFromPush:(NSString*)visitorName visitorEmail:(NSString*)visitorEmail visitorMobile:(NSString*)visitorMobile loginState:(enum LState) loginState onNavigationViewController:(UINavigationController *)navVC;



//Used for API Get-Global
@property (nonatomic,assign) BOOL isTokenCustomPacketAlreadySent;
@property (strong,nonatomic) NSString* token;


- (void)setChatBotID:(NSString*)chatBotID;
- (void)setSessionID:(NSString*)sessionID;
- (NSString *)getChatBotID;
- (NSString *)getSessionID;
- (void)clearChatBotIDAndSessionID;
- (BOOL)isChatBotIDAndSessionIDAvailable;

@end
