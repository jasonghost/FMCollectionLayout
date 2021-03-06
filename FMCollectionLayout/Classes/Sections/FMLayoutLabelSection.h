//
//  FMLayoutLabelSection.h
//  FMCollectionLayout
//
//  Created by 郑桂华 on 2020/4/8.
//

#import "FMLayoutBaseSection.h"
#import "FMCollectionViewElement.h"
NS_ASSUME_NONNULL_BEGIN

///返回cell大小的block
typedef CGFloat(^FMLayoutItemWidthBlock)(id section, NSInteger item);

///当到第多少个的时候超出最大行  可移除数据处理  itemDatas会清理 否则frame为zero
typedef CGFloat(^FMLayoutOverItemBlock)(id section, NSInteger item);

///标签式布局   根据文本伸缩布局  宽度不够  换行    适用于历史搜索记录  sku选择等样式
@interface FMLayoutLabelSection : FMLayoutBaseSection

@property(nonatomic, strong)FMCollectionViewElement *cellElement;///固定分组
@property(nonatomic, assign)NSInteger maxLine;

@property(nonatomic, assign)CGFloat cellFixedHeight;///cell固定的高度
@property(nonatomic, assign)CGFloat cellMaxWidth;///cell最大宽度  不设置的话  就是collection的宽度减去左右分组内边距
@property(nonatomic, copy)FMLayoutItemWidthBlock widthBlock;///block返回手动计算的宽度
@property(nonatomic, copy)FMLayoutOverItemBlock overItemBlock;///block返回手动计算的宽度


@property(nonatomic, assign)BOOL isSingleLineCanScroll;
@property(nonatomic, copy)void(^scrollDidScrollBlock)(CGFloat offsetX, CGFloat contentWidth);///内嵌collectionView横向滚动的偏移以及大小

@end

NS_ASSUME_NONNULL_END
