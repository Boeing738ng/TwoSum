# TwoSum 项目

## 项目简介

TwoSum 是一个用 C++ 实现的经典算法项目，用于解决"两数之和"问题。该项目实现了在给定数组中寻找两个数字，使它们的和等于目标值的算法。

## 问题描述

给定一个整数数组 `numbers` 和一个目标值 `target`，在数组中找出和为目标值的那两个整数，并返回他们的数组下标。

**要求：**
- 假设每个输入只对应一个答案
- 不能重复利用这个数组中同样的元素
- 返回的下标从 1 开始（不是从 0 开始）

## 功能特性

- 🚀 **高效算法**：使用哈希表实现 O(n) 时间复杂度
- 🎯 **准确结果**：保证找到唯一解
- 📝 **清晰代码**：代码结构清晰，易于理解
- 🛠️ **Xcode 项目**：完整的 Xcode 项目结构

## 项目结构

```
TwoSum/
├── TwoSum.xcodeproj/     # Xcode 项目文件
├── TwoSum/
│   ├── main.cpp          # 主程序文件
│   └── twoSum.h          # 头文件
└── README.md             # 项目说明文档
```

## 核心算法

### 实现思路

使用哈希表（`unordered_map`）来存储已经遍历过的数字及其索引：

1. 遍历数组中的每个元素
2. 对于当前元素 `numbers[i]`，计算需要寻找的补数：`target - numbers[i]`
3. 检查哈希表中是否已经存在这个补数
4. 如果存在，返回当前索引和补数的索引
5. 如果不存在，将当前数字及其索引加入哈希表

### 时间复杂度

- **时间复杂度**：O(n) - 只需要遍历一次数组
- **空间复杂度**：O(n) - 最坏情况下需要存储所有元素

## 使用方法

### 编译运行

1. 使用 Xcode 打开 `TwoSum.xcodeproj`
2. 选择目标平台（macOS）
3. 点击运行按钮或使用快捷键 `Cmd + R`

### 示例代码

```cpp
#include <iostream>
#include <vector>
#include "twoSum.h"

int main() {
    vector<int> input = {2, 7, 11, 15};
    int target = 9;
    vector<int> output = twoSum(input, target);
    
    // 输出结果
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
    // 输出: 2 1 (表示第2个和第1个元素的和为9)
    
    return 0;
}
```

## 测试用例

| 输入数组 | 目标值 | 期望输出 | 说明 |
|---------|--------|----------|------|
| [2, 7, 11, 15] | 9 | [2, 1] | 2 + 7 = 9 |
| [3, 2, 4] | 6 | [3, 2] | 2 + 4 = 6 |
| [3, 3] | 6 | [2, 1] | 3 + 3 = 6 |

## 技术实现细节

### 核心函数

```cpp
vector<int> twoSum(vector<int> &numbers, int target)
{
    unordered_map<int, int> hash;
    vector<int> ret;
    
    for (int i = 0; i < numbers.size(); i++) {
        int numToFind = target - numbers[i];
        
        if (hash.find(numToFind) != hash.end()) {
            ret.push_back(i + 1);           // 当前元素索引（从1开始）
            ret.push_back(hash[numToFind] + 1); // 补数索引（从1开始）
            return ret;
        }
        
        hash[numbers[i]] = i;  // 存储当前数字及其索引
    }
    
    return ret;
}
```

### 关键特性

- **哈希表优化**：使用 `unordered_map` 实现 O(1) 的查找时间
- **一次遍历**：只需要遍历数组一次即可找到解
- **索引调整**：返回的索引从 1 开始，符合题目要求

## 开发环境

- **IDE**: Xcode
- **语言**: C++
- **标准**: C++11 或更高版本
- **平台**: macOS

## 作者信息

- **作者**: BOEING
- **创建时间**: 2017年11月1日
- **版权**: © 2017 BOEING. All rights reserved.

## 许可证

本项目采用私有许可证，版权所有。

## 更新日志

### v1.0.0 (2017-11-01)
- 初始版本发布
- 实现基本的 TwoSum 算法
- 添加 Xcode 项目支持

---

*如有问题或建议，请联系项目维护者。*