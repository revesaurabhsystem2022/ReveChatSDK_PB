//
//  LoginState.h
//  ReveChat
//
//  Created by Amit on 5/15/17.
//  Copyright © 2017 Amit. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger, LState) {
    LOGGED_IN,
    LOGGED_OUT
};



@interface LoginState : NSObject
{
    enum LState loginState;
}

- (void)setLoginState:(LState)newState;
+ (instancetype)sharedInstance;
// Method to check login state
- (BOOL)isLoggedIn;



@end
