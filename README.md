# Problem 057 - 学生成绩管理系统

**ACMOJ Problem ID**: 14083

## Table of Contents

- [Problem 057 - 学生成绩管理系统](#problem-057-学生成绩管理系统)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

Implement student grade management system: add, query, display, sort by ID/grade.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **14083. 学生成绩管理系统** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/057/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

author: 程序设计思想与方法助教组 Te Qi
原OJ链接：https://acm.sjtu.edu.cn/OnlineJudge-old/problem/4083
## 问题描述

此题与实验指导书原题**不同**。由于OJ系统不能输入多个cpp文件，本题不必进行模块划分。

设计一个学生成绩管理程序，实现对n个学生的成绩的记录与统计工作。学生信息包括：学号、姓名、成绩。
程序基本功能要求如下：

- 能够新增学生信息
- 能够分别根据学号和姓名查询该学生的基本信息
- 能够显示所有学生的成绩信息
- 能够分别按照学号和成绩进行排序

要求实现如下功能（注意以下编号与实验指导书中**不同**）：

	1-添加学生信息
	2-显示全部学生信息
	3-按学号查询学生信息
	4-按姓名查询学生信息
	5-按学号升序排序
	6-按成绩降序排序
	7-退出

本题中**不要输出**该菜单，而要按照其**识别输入编号**，并输出相应信息。

## 输入输出
### 输入

输入信息为**多行**（1<=N<=10000），每一行是一条指令。对于每一条指令，第一个数字为“指令编号”，后续数据为指令所需的信息（例如“添加学生信息”需要学生的学号、姓名、成绩），这些数据以**空格分隔**，格式如下：

	指令编号 信息1 信息2 信息3 ...

对于每一种指令，输入格式分别具体如下：

##### 添加学生信息

	1 学号 姓名 成绩

其中“1”为“添加学生信息”的指令编号，以下其他指令类同。

学号为**9位数字**；姓名为英文，长度**不超过19个字符(1<=len(name)<=19)**，不包含空格，不存在学生重名情况；成绩为**0或正整数并且不超过100(0<=s<=100)**。

注意：若输入的学号与先前已添加的学生学号重复，**丢弃**该数据，不要将该数据录入。

##### 显示全部学生信息

	2

##### 按学号查询学生信息

	3 学号

查询的学号一定存在。

##### 按姓名查询学生信息

	4 姓名

查询的姓名一定存在。

##### 按学号升序排序

	5

##### 按成绩降序排序

	6

##### 退出

	7

### 输出

##### 添加学生信息

如果当前学生未添加过（也即当前学号不在先前已添加学号列表中）：

	SUCCESS

否则（当前学号已在列表中）：

	FAILED

此时**直接丢弃**该数据，不要录入。

##### 显示全部学生信息

按照数据添加顺序输出（最先添加的学生在第一行）

	学号1 姓名1 成绩1
	学号2 姓名2 成绩2
	...
	学号n 姓名n 成绩n

注意：无数据时不输出任何字符，不要产生空行

##### 按学号查询学生信息

	学号 姓名 成绩

##### 按姓名查询学生信息

	学号 姓名 成绩

##### 按学号升序排序

排序后按以下格式输出

	学号1 姓名1 成绩1
	学号2 姓名2 成绩2
	...
	学号n 姓名n 成绩n

注意：无数据时不输出任何字符，不要产生空行

##### 按成绩降序排序

排序后按以下格式输出

	学号1 姓名1 成绩1
	学号2 姓名2 成绩2
	...
	学号n 姓名n 成绩n

注意：无数据时不输出任何字符，不要产生空行；成绩相同时，按照**添加先后顺序**输出。

##### 退出

	END

## 示例

输入：

	2
	1 100000001 Mike 98
	1 100000003 Will 100
	1 100000002 Eleven 98
	1 100000003 Will 100
	3 100000003
	4 Eleven
	2
	6
	5
	7

程序应该按如下步骤运行：

1. 输出全部学生信息，由于无数据，不输出
2. 成功添加学生“Mike”信息，输出一行“SUCCESS”
3. 成功添加学生“Will”信息，输出一行“SUCCESS”
4. 成功添加学生“Eleven”信息，输出一行“SUCCESS”
5. 尝试添加学生“Will”信息，但学号"100000003"已在列表中，因此丢弃该数据并输出一行“FAILED”
6. 查询学号“100000003”信息，输出一行“100000003 Will 100”
7. 查询学生“Eleven”信息，输出一行"100000002 Eleven 98"
8. 输出全部学生信息，示例输出第7-9行
9. 按成绩降序排序并输出，示例输出第10-12行
10. 按学号升序排序并输出，示例输出第13-15行
11. 程序结束，结束前输出一行“END”

所以全部输出为：

	SUCCESS
	SUCCESS
	SUCCESS
	FAILED
	100000003 Will 100
	100000002 Eleven 98
	100000001 Mike 98
	100000003 Will 100
	100000002 Eleven 98
	100000003 Will 100
	100000001 Mike 98
	100000002 Eleven 98
	100000001 Mike 98
	100000002 Eleven 98
	100000003 Will 100
	END

### Input Format

See the problem description above.

### Output Format

See the problem description above.

### Samples

No sample data provided for this problem.

### Data Constraints

See the problem description for constraints.

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 1000 ms
- **Memory Limit (per test case)**: 256 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/057/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
