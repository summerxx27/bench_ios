//
//  CC_UiHelper.h
//  NewWord
//
//  Created by gwh on 2017/12/15.
//  Copyright © 2017年 gwh. All rights reserved.
//

#define CC_SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define CC_SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface CC_UIHelper : NSObject

@property (nonatomic,retain) UIView *toolV;
@property (nonatomic,retain) UIView *lastV;

@property (nonatomic,assign) float uiDemoWidth;
@property (nonatomic,assign) float uiDemoHeight;

/**
 *  模型文件路径列表
 */
@property (nonatomic,retain) NSMutableArray *modelPaths;
/**
 *  模型路径对应模型名称的字典
 */
@property (nonatomic,retain) NSMutableDictionary *modelsDic;

+ (instancetype)getInstance;
/*
 * 初始化 必须放入ui图尺寸 整个app以后的效果图全部以这个为尺寸
 * [[CC_UIHelper getInstance]initUIDemoWidth:375 andHeight:568];
 */
- (void)initUIDemoWidth:(float)width andHeight:(float)height;
- (float)getUIDemoWith;
- (float)getUIDemoHeight;

/**
 *  添加app用的到的模型文件夹路径
    可添加多个 建议1个app用1个管理
    return 返回该路径下模型个数
 */
- (int)addModelDocument:(NSString *)path;
/**
 *  添加完路径 把路径加载到内存
    这里不读取文件加载到内存 防止浪费内存
 */
- (int)initModels;

- (void)initToolV;

@end

@interface ccui : NSObject

/**
 *  oc代码获取的状态栏高度
 */
+ (float)getStatusH;
+ (float)getX;
/**
 *  刘海的高度
 */
+ (float)getY;
/**
 *  状态栏高度
 */
+ (float)getSY;
/**
 *  设备宽度
 */
+ (float)getW;
/**
 *  去掉刘海的高度
 */
+ (float)getH;
/**
 *  减去状态栏的高度
 */
+ (float)getSH;

/*
 * height ui图标注的值
 * 获取根据效果图标注的适配其他机型的尺寸
 */
+ (float)getRH:(float)height;
+ (float)getRelativeHeight:(float)height;

/*
 * 如果ui图和初始化的不一样 比如以前规定用iphone6尺寸 但是这张效果图是iphone7plus尺寸时
 */
//+ (float)getRelativeHeight:(float)height withTempUIDemoWidth:(float)width andHeight:(float)height;

/*
 * obj 要调整的控件
 * 原来frame里必须是绝对值
 * x不居中
 */
+ (CGRect)adjustRelativeRect:(UIView *)obj;
/*
 * arr = @[@x @y @width @height]
 */
+ (CGRect)adjustRelativeRect:(UIView *)obj withFrameArr:(NSArray *)arr;


+ (UIFont *)getRFS:(float)fontSize;
/*
 * fontName 字体名 默认字体传nil
 * fontSize 字体标注尺寸
 * 获取根据效果图标注的适配其他机型的字体
 */
+ (UIFont *)getRelativeFont:(NSString *)fontName fontSize:(float)fontSize;
/*
 * fontName 字体名 默认字体传nil
 * fontSize 字体标注尺寸
 * baseFontSize 如果在其他机型的放大比例不适合 通过baseFontSize调整
 */
+ (UIFont *)getRelativeFont:(NSString *)fontName fontSize:(float)fontSize baseFontSize:(float)baseFontSize;

@end
