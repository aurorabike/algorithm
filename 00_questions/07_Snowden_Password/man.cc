/* 
*  Question: Snowden’s Password https://www.luogu.com.cn/problem/P1603#ide
*  2013 年 X 月 X 日，俄罗斯办理了斯诺登的护照，于是他混迹于一架开往委内瑞拉的飞机。但是，这件事情太不周密了，因为 FBI 的间谍早已获悉他的具体位置——但这不是最重要的——最重要的是如果要去委内瑞拉，那么就要经过古巴，而经过古巴的路在美国的掌控之中。
*  
*  丧心病狂的奥巴马迫降斯诺登的飞机，搜查时却发现，斯诺登杳无踪迹。但是，在据说是斯诺登的座位上，发现了一张纸条。纸条由纯英文构成：Obama is a two five zero.（以 . 结束输出，只有 6 个单词 + 一个句号，句子开头如没有大写亦为合法）这句话虽然有点无厘头，但是警官陈珺骛发现这是一条极其重要的线索。他在斯诺登截获的一台笔记本中找到了一个 C++ 程序，输入这条句子后立马给出了相对应的密码。陈珺鹜高兴得晕了过去，身为警官的你把字条和程序带上了飞机，准备飞往曼哈顿国际机场，但是在飞机上检查的时候发现——程序被粉碎了！飞机抵达华盛顿只剩 5 分钟，你必须在这 5 分钟内编写（杜撰）一个程序，免受上司的 10000000000mod10 大板。破译密码的步骤如下：
*  
*  找出句子中所有用英文表示的数字 (≤20)，列举在下：
*  **正规：zero one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty
*  **非正规：a both another first second third
*  **为避免造成歧义，another 算作 1 处理。
*  将这些数字平方后对 100 取模，如 0→0→00，5→25→25，19→361→61。
*  把这些两位数（按任意顺序）按数位排成一行，组成一个新数，如果开头为 0，就去 0，如 {00,25,61}→2561。
*  找出所有排列方法中最小的一个数，即为密码。
*  输入格式
*  一个含有 6 个单词的句子。
*  
*  保证整个句子的字符个数（包括空格）不超过 1000。
*  
*  输出格式
*  一个整型变量（密码）。如果没有符合要求的数字出现，则输出 0。
*  
*  输入输出样例
*  输入 Black Obama is two five zero .
*  输出 425
*/
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::string> splitWords(const std::string& str) {
        std::vector<std::string> res;
        for(int i = 0; i < str.length(); i++) {
            std::string word = "";
            while(i < str.length() && str[i] != ' ') {
                word += str[i];
                i++;
            }
            if(!word.empty()) {
                res.push_back(word);
            }
        }
        return res;
    }
    
    int getNum(const std::string& raw) {
        std::string s;
        for(char c: raw) {
            if (std::isalpha((unsigned char)c)) s += std::tolower((unsigned char)c);
        }

        static const std::unordered_map<std::string,int> mp = {
            {"zero",0},{"one",1},{"two",2},{"three",3},{"four",4},{"five",5},
            {"six",6},{"seven",7},{"eight",8},{"nine",9},{"ten",10},
            {"eleven",11},{"twelve",12},{"thirteen",13},{"fourteen",14},{"fifteen",15},
            {"sixteen",16},{"seventeen",17},{"eighteen",18},{"nineteen",19},{"twenty",20},
            // informal forms
            {"a",1},{"both",2},{"another",1},{"first",1},{"second",2},{"third",3}
        };

        auto it = mp.find(s);
        if (it != mp.end()) return it->second;
        return -1;
    }

    // Solve one input line and return result as string
    std::string calculate(const std::string& line) {
        auto words = splitWords(line);
        std::vector<std::string> parts;
        for (auto &w: words) {
            int v = getNum(w);
            if (v >= 0 && v <= 20) {
                int m = (v * v) % 100;
                char buf[3];
                std::snprintf(buf, sizeof(buf), "%02d", m);
                parts.push_back(std::string(buf));
            }
        }

        if (parts.empty()) return "0";

        std::sort(parts.begin(), parts.end(), [](const std::string &a, const std::string &b){
            return a + b < b + a;
        });

        std::string all;
        for (auto &p: parts) all += p;

        // strip leading zeros
        size_t pos = 0;
        while (pos < all.size() && all[pos] == '0') pos++;
        if (pos == all.size()) return "0";
        return all.substr(pos);
    }
};

int main() {
    std::string line;
    // read full line (sentence)
    std::getline(std::cin, line);
    Solution sol;
    std::string out = sol.calculate(line);
    std::cout << out << std::endl;
    return 0;
}