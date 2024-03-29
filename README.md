

# 解决哈希冲突的四种常用方法：

## 1、开放地址法
这种方法也称再散列法，基本思想是当关键字key的哈希地址p = H(key)冲突时，
以p为基础再产生一个新的哈希地址p1，p1再冲突时，再以p为基础，产生地址p2……直到产生一个不冲突的地址pi，
再将key填入其中，这种方法都有一个通用的再散列表达式
Hi = (H（key）+ di)%m
其中H（key）是哈希函数，m为表长，di是增量序列，增量的取值方式不同，相应的再散列方式也不相同，
（1）线性探测再散列
i = 1，2，3，4……..m-1.
采用这种方法冲突发生时，查看下一单元，直到找到一个空的单元，或者遍历全表。
（2）二次探测再散列
m = 1^2,-1^2 ,2^2,-2^2……k^2,-k^2.(k < m/2).
采用这种方法冲突发生时在表的左右进行探测比较灵活。
（3）伪随机探测再散列
i = 伪随机数序列
具体实现时需要建立一个伪随机数生成器，并给定一个随机数做为起点。

## 2、拉链法
这种方法的基本思想是，将所有哈希地址为i的元素构成一个同义词链的单链表。将单链表的头指针存放在单链表的第i个单元中。

## 3、再哈希法[Double Hashing](https://www.geeksforgeeks.org/double-hashing/)
再哈希法是同时构造多个不同的哈希函数
Hi = RHi(key）i=1,2,3,4,5,….,k
如果RH1(key）冲突，就采用RH2(key），直到不在产生冲突为止，这种方法不易产生聚集，但是增加量计算时间。
经典的第一个哈希函数是 hash1(key) = key % TABLE_SIZE
比较常用的第二个哈希函数是hash2(key) = PRIME – (key % PRIME) 
PRIME是一个比哈希表长度小的一个值。
比较好的第二个哈希函数一般要满足：计算结果不能等于0，并确保哈希表所有桶都要遍历到。

## 4、建立公共溢出区
这种方法的思想是哈希表分为基本表和溢出表。和基本表冲突的元素都填入溢出表。

## 优缺点
优点：
①拉链法处理冲突简单，且无堆积现象，即非同义词决不会发生冲突，因此平均查找长度较短；
②由于拉链法中各链表上的结点空间是动态申请的，故它更适合于造表前无法确定表长的情况；
③开放定址法为减少冲突，要求装填因子α较小，故当结点规模较大时会浪费很多空间。而拉链法中可取α≥1，且结点较大时，拉链法中增加的指针域可忽略不计，因此节省空间；
④在用拉链法构造的散列表中，删除结点的操作易于实现。只要简单地删去链表上相应的结点即可。
而对开放地址法构造的散列表，删除结点不能简单地将被删结 点的空间置为空，否则将截断在它之后填人散列表的同义词结点的查找路径。
这是因为各种开放地址法中，空地址单元(即开放地址)都是查找失败的条件。
因此在 用开放地址法处理冲突的散列表上执行删除操作，只能在被删结点上做删除标记，而不能真正删除结点。

缺点：
指针需要额外的空间，故当结点规模较小时，开放定址法较为节省空间，而若将节省的指针空间用来扩大散列表的规模，可使装填因子变小，
这又减少了开放定址法中的冲突，从而提高平均查找速度。




