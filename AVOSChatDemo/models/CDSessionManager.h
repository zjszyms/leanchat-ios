//
//  CDSessionManager.h
//  AVOSChatDemo
//
//  Created by Qihe Bian on 7/29/14.
//  Copyright (c) 2014 AVOS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CDCommon.h"
#import "CDMsg.h"
#import "CDChatGroup.h"

@interface CDSessionManager : NSObject <AVSessionDelegate, AVSignatureDelegate, AVGroupDelegate>
+ (instancetype)sharedInstance;

@property NSMutableArray* friends;

#pragma mark - conversation
-(void)findConversationsWithCallback:(AVArrayResultBlock)callback;

#pragma mark - session
- (void)watchPeerId:(NSString *)peerId;
-(void)unwatchPeerId:(NSString*)peerId;
-(void)openSession;
-(void)closeSession;

#pragma mark - operation message
- (void)sendMessageWithType:(CDMsgType)type content:(NSString *)content  toPeerId:(NSString *)toPeerId group:(AVGroup*)group;
- (void)sendAttachmentWithObjectId:(NSString*)objectId type:(CDMsgType)type toPeerId:(NSString *)toPeerId group:(AVGroup*)group;

- (NSArray*)getMsgsForConvid:(NSString*)convid;
-(NSArray*)getMsgsWithConvid:(NSString*)convid maxTimestamp:(int64_t)timestamp limit:(int)limit;

+(NSString*)getConvidOfRoomType:(CDMsgRoomType)roomType otherId:(NSString*)otherId groupId:(NSString*)groupId;
- (void)clearData;
+(NSString*)convidOfSelfId:(NSString*)myId andOtherId:(NSString*)otherId;
+(NSString*)getPathByObjectId:(NSString*)objectId;
+(NSString*)uuid;

-(int64_t)getMaxTimetstamp;

#pragma mark - database
-(void)upgradeToAddField;
-(void)markHaveReadOfMsgs:(NSArray*)msgs;

#pragma mark - histroy
- (void)getHistoryMessagesForPeerId:(NSString *)peerId callback:(AVArrayResultBlock)callback;
- (void)getHistoryMessagesForGroup:(NSString *)groupId callback:(AVArrayResultBlock)callback;

#pragma mark - group
- (AVGroup *)joinGroupById:(NSString *)groupId;
- (void)saveNewGroupWithName:(NSString*)name withCallback:(AVGroupResultBlock)callback ;
-(void)inviteMembersToGroup:(CDChatGroup*) chatGroup userIds:(NSArray*)userIds;
-(void)kickMemberFromGroup:(CDChatGroup*)chatGroup userId:(NSString*)userId;
-(void)quitFromGroup:(CDChatGroup*)chatGroup;

#pragma mark - user cache
- (void)registerUsers:(NSArray*)users;
- (void)registerUser:(AVUser*)user;
- (AVUser *)lookupUser:(NSString*)userId;
-(void)cacheUsersWithIds:(NSArray*)userIds callback:(AVArrayResultBlock)callback;


@end
