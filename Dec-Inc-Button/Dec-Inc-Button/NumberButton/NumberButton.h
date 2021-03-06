//
//  NumberButton.h
//  Dec-Inc-Button
//
//  Created by xiangronghua on 2017/2/4.
//  Copyright © 2017年 xiangronghua. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol NumberButtonDelegate <NSObject>
@optional
/**
 加减代理回调
 
 @param numberButton 按钮
 @param number 结果
 @param increaseStatus 是否为加状态
 */
- (void)pp_numberButton:(__kindof UIView *)numberButton number:(NSInteger)number increaseStatus:(BOOL)increaseStatus;
@end

@interface NumberButton : UIView

/** 加减按钮的Block回调*/
@property (copy, nonatomic) void(^resultBlock)(NSInteger number, BOOL increaseStatus/* 是否为加状态*/);
@property (weak, nonatomic) id<NumberButtonDelegate> delegate;

#pragma mark -- 自定义样式属性设置
/** 是否开启抖动动画, default is NO*/
@property (assign, nonatomic) IBInspectable BOOL shakeAnimation;
/** 为YES时,初始化时减号按钮隐藏(饿了么/百度外卖/美团外卖按钮模式),default is NO*/
@property (assign, nonatomic) IBInspectable BOOL decreaseHide;
/** 是否可以使用键盘输入,default is YES*/
@property (getter=isEditing, assign, nonatomic) IBInspectable BOOL editing;
/** 设置边框的颜色,如果没有设置颜色,就没有边框*/
@property (assign, nonatomic) IBInspectable UIColor *borderColor;
/** 输入框中的内容*/
@property (assign, nonatomic) NSInteger currentNumber;
/** 输入框中的字体大小*/
@property (assign, nonatomic) IBInspectable CGFloat inputFieldFont;
/** 加减按钮的字体大小*/
@property (assign, nonatomic) IBInspectable CGFloat buttonTitleFont;
/** 加按钮背景图片*/
@property (strong, nonatomic) IBInspectable UIImage *increaseImage;
/** 减按钮背景图片*/
@property (strong, nonatomic) IBInspectable UIImage *decreaseImage;
/** 加按钮标题*/
@property (copy,  nonatomic) IBInspectable NSString *increaseTitle;
/** 减按钮标题*/
@property (copy,  nonatomic) IBInspectable NSString *decreaseTitle;
/** 最小值, default is 1 */
@property (assign, nonatomic) IBInspectable NSInteger minValue;
/** 最大值*/
@property (assign, nonatomic) IBInspectable NSInteger maxValue;

#pragma mark-- 初始化方法
- (instancetype)initWithFrame:(CGRect)frame;
+ (instancetype)numberButtonWithFrame:(CGRect)frame;

@end
#pragma mark - NSString分类
@interface NSString (NumberButton)
/**
 字符串 nil, @"", @"  ", @"\n" Returns NO;
 其他 Returns YES.
 */
- (BOOL)pp_isNotBlank;

@end
