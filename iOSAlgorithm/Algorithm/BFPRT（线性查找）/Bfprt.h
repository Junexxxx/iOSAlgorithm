
#import <Foundation/Foundation.h>

@interface Bfprt : NSObject

+ (NSInteger)selectModify:(NSMutableArray *)array withNum:(NSInteger)n;

@end

/******************************
 五划分中项的中项法就是BFPRT算法
 
BFPRT算法解决的问题十分经典，即从某n个元素的序列中选出第k大（第k小）的元素，通过巧妙的分 析，BFPRT可以保证在最坏情况下仍为线性时间复杂度。该算法的思想与快速排序思想相似，当然，为使得算法在最坏情况下，依然能达到o(n)的时间复杂度.
 
 终止条件：n=1时，返回的即是i小元素。
 算法步骤：
 step1：将n个元素每5个一组，分成n/5(上界)组，最后的一个组的元素个数为n%5，有效的组数为n/5。
 step2：取出每一组的中位数，最后一个组的不用计算中位数，任意排序方法，这里的数据比较少只有5个，
 可以用简单的冒泡排序或是插入排序。
 setp3 :  将各组的中位数与数组开头的数据在组的顺序依次交换，这样各个组的中位数都排在了数据的左边。
 递归的调用中位数选择算法查找上一步中所有组的中位数的中位数，设为x，偶数个中位数的情况下设定为选取中间小的一个。
 setp4:   按照x划分,大于或者等于x的在右边,小于x的在左边，关于setp4数据的划分，中位数放在左边或是右边会有些影响。
 后面的代码调试将会看到。
 step5：setp4中划分后数据后返回一个下表i，i左边的元素均是小于x，i右边的元素包括i都是大于或是等于x的。
 若i==k，返回x；
 若i<k，在小于x的元素中递归查找第i小的元素；
 若i>k，在大于等于x的元素中递归查找第i-k小的元素。
 
 *****************************/
