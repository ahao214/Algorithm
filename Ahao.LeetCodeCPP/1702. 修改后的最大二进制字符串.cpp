#include<vector>
#include<string>


using namespace std;



/*
1702. 修改后的最大二进制字符串
给你一个二进制字符串 binary ，它仅有 0 或者 1 组成。你可以使用下面的操作任意次对它进行修改：

操作 1 ：如果二进制串包含子字符串 "00" ，你可以用 "10" 将其替换。
比方说， "00010" -> "10010"
操作 2 ：如果二进制串包含子字符串 "10" ，你可以用 "01" 将其替换。
比方说， "00010" -> "00001"
请你返回执行上述操作任意次以后能得到的 最大二进制字符串 。如果二进制字符串 x 对应的十进制数字大于二进制字符串 y 对应的十进制数字，那么我们称二进制字符串 x 大于二进制字符串 y 。
*/
class Solution {
public:
	/*
	遇见第一个0的时候，向后面找到第二个0，将第二个0去掉，在前面的0之前加上一个数字1
	继续上面的操作，直到字符里面只剩下一个0的时候结束
	综上可以知道，值需要知道第一个0后面有多少个0，第一个0就会向后面移动几位
	先找到第一个0的位置，假设为K，在找出第一个0后面的0的个数，假设为cnt，那么最后的结果中，K+cnt的位置是0，其他位置都是1
	*/
	string maximumBinaryString(string binary) {
		int k = 0;
		while (k < binary.size() && binary[k] == '1') k++;
		if (k == binary.size()) return binary;
		int cnt = 0;
		for (int i = k + 1; i < binary.size(); i++)
		{
			if (binary[i] == '0')
				cnt++;
		}
		string res(binary.size(), '1');
		res[k + cnt] = '0';
		return res;
	}
};
