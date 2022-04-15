
## Boosting  
集成学习：构建并结合多个机器学习来完成整个学习任务  
## Adaptive  
自适应：迭代 增加误差率小的权重、降低误差率大的权重  

***
## 过程目标  
* 计算学习误差率e
* 计算弱学习器权重系数α
* 计算样本权重D
* 选择结合策略
***
## 建立不同的弱学习器  
* 使用不同的弱学习算法
* 使用相同的弱学习算法，但使用不同参数
* 使用不同的特征
* 使用不同的训练集
***
## 组合  
* 多专家组合。eg.投票(voting)
* 多级组合。eg.级联(cascading)
***
# 算法
输入：训练数据集T={(x_1,y_1),(x_2,y_2),...,(x_N,y_N)}，其中x_i\inX\subseteqR^n，y_i\inY={+1,-1},i=1,2,...,N；弱学习算法  
输出：分类器G(x)
1. 初始化训练数据的权值分布  
    > 	$D_1=(w_11,w_12,...,w_1N),w_1i=\frac 1N,i=1,2,...,N$

2. 对m=1,2,...,M  
    - 使用具有权值分布D_m的训练数据集学习，得到基本分类器
	    > G_m(x):X\to{-1,+1}
    - 计算G_m(x)在训练数据集上的分类误差率
	    > e_m=\sum_{i=1}^NP(G_m(x_i)\ney_i)=\sum_{i=1}^Nw_miI(G_m(x_i)\ney_i)
    - 计算G_m(x)的系数
	    > \alpha_m=\frac 12log\frac {1-e_m}{e_m}
    - 更新训练数据集的权值分布
	    > D_m+1=(w_{m+1,1},...,w_{m+1,i},...,w_{m+1,N})  
	    > w_{m+1,i}={w_mi/over Z_m}exp(-/alpha_my_iG_m(x_i))
	    > =\begin{cases}
	    > {w_mi/over Z_m}exp(-/alpha_m), G_m(x_i)=y_i
	    > {w_mi/over Z_m}exp(/alpha_m), G_m(x_i)\ney_i
	    > \end{cases}
	    > i=1,2,...,N  
	    > 其中,Z_m是规范化因子:  
	    > Z_m=\sum_{i=1}^Nw_miexp(-/alpha_my_i,G_m(x_i))
3. 构建基本分类器的线性组合
    > f(x)=\sum_{m=1}^M/alpha_mG_m(x)  
    > 得到最终分类器  
    > G(x)=sign(f(x))=sign(\sum_{m=1}^M/alpha_mG_m(x))
***
