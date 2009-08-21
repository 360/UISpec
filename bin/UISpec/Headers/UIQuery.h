//
//  UIQuery.h
//  UISpec
//
//  Created by Brian Knorr <btknorr@gmail.com>
//  Copyright(c) 2009 StarterStep, Inc., Some rights reserved.
//
#import "ViewFilterSwizzler.h"

@class UIFilter, UIExpectation, UIRedoer;

UIQuery * $(NSString *script, ...);

@interface UIQuery : ViewFilterSwizzler {
	UIQuery *first, *last, *all, *redo;
	UIFilter *with;
	UIExpectation *should;
	UIQuery *parent, *child, *descendant, *find;
	UIQuery *touch, *show, *flash, *path, *inspect;
	NSMutableArray *views;
	NSString *className;
	UIRedoer *redoer;
	int timeout;
	BOOL filter, exists;
}

@property(nonatomic, readonly) UIFilter *with;
@property(nonatomic, readonly) UIExpectation *should;
@property(nonatomic, readonly) UIQuery *parent, *child, *descendant, *find;
@property(nonatomic, readonly) UIQuery *touch, *flash, *show, *path, *inspect;
@property int timeout;
@property(nonatomic, retain) NSMutableArray *views;
@property(nonatomic, retain) NSString *className;
@property(nonatomic, retain) UIRedoer *redoer;
@property(nonatomic, readonly) UIQuery *first, *last, *all, *redo;
@property BOOL exists;

-(UIQuery *)view:(NSString *)className;
-(UIQuery *)index:(int)index;
-(UIQuery *)timeout:(int)seconds;
-(UIQuery *)wait:(double)seconds;
-(UIQuery *)target;

+(id)withApplicaton;
+(void)show:(NSArray *)views;

@end

