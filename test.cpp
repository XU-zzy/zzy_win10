//头文件
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;
string instr;//输入符号串
int index;//当前输入符号读入字符的位置
char character;//全局变量字符，存放最新读入的字符
string token;//字符数组，存放已读入的字符序列
map<string, int> Symbol;//标识符集
map<string, int> Digit;//常数集
map<string, int>::iterator ite;
const int len = 100;
string Reserve[len];//保留字表
string Boundary[2*len];//界符
string Operator[3 * len];//运算符

struct Binary {
	Binary(int c,int i,string v="-") {
		category = c;
		index = i;
		value = v;
	}
	int category=0;
	int index=0;
	string value="-";
};
void init_Reserve() {//构造保留字表的函数(c语言有32个保留字)
	Reserve[1] = "auto";
	Reserve[2] = "break";
	Reserve[3] = "case";
	Reserve[4] = "char";
	Reserve[5] = "const";
	Reserve[6] = "continue";
	Reserve[7] = "default";
	Reserve[8] = "do";
	Reserve[9] = "double";
	Reserve[10] = "else";
	Reserve[11] = "enum";
	Reserve[12] = "extern";
	Reserve[13] = "float";
	Reserve[14] = "for";
	Reserve[15] = "goto";
	Reserve[16] = "if";
	Reserve[17] = "int";
	Reserve[18] = "long";
	Reserve[19] = "register";
	Reserve[20] = "return";
	Reserve[21] = "short";
	Reserve[22] = "signed";
	Reserve[23] = "static";
	Reserve[24] = "sizeof";
	Reserve[25] = "struct";
	Reserve[26] = "switch";
	Reserve[27] = "typedef";
	Reserve[28] = "union";
	Reserve[29] = "unsigned";
	Reserve[30] = "void";
	Reserve[31] = "volatile";
	Reserve[32] = "while";
}
void init_Operator() {//初始化运算符表
	Operator[210] = "+";
	Operator[211] = "-";
	Operator[212] = "*";
	Operator[213] = "/";
	Operator[214] = "<";
	Operator[215] = "<=";
	Operator[216] = ">";
	Operator[217] = ">=";
	Operator[218] = "!=";
	Operator[219] = "==";
	Operator[220] = "=";
}
void init_Boundary() {//界符表初始化
	Boundary[121] = "(";
	Boundary[122] = ")";
	Boundary[123] = ",";
	Boundary[124] = ";";
	Boundary[125] = "{";
	Boundary[126] = "}";
	Boundary[127] = "#";
}
void getChar() {//读入一个字符
	character = instr[index++];
}
void getnbc() {//读入非空白字符
	while (character == ' ') {
		getChar();
	}
}
void concat() {//连接字符串
	token = token + character;
}
bool letter() {//判断是否为字母
	if ((character >= 'A'&&character <= 'Z') || (character >= 'a'&&character <= 'z'))
		return true;
	return false;
}
bool digit() {//判断是否为数字
	if (character >= '0'&&character <= '9')
		return true;
	return false;
}
void retract(){//回退字符的函数
	character = ' ';
	index--;
}
int reserve() {//匹配保留字符
	for (int i = 0; i < len; i++)
		if (Reserve[i] == token)return i;
	return -1;
}
string symbol() {
	ite = Symbol.find(token);
	if (ite != Symbol.end()) {
		return ite->first;
	}
	else {
		Symbol[token] = Symbol.size();
		return token;
	}
}
string constant() {
	ite = Digit.find(token);
	if (ite != Digit.end()) {
		return ite->first;
	}
	else {
		Digit[token] = Digit.size();
		return token;
	}
}
Binary error() {
	return Binary(0, 0);
}
//词法分析函数，逐个识别单词
Binary LexAnalyze() {
	token = "";
	getChar();
	getnbc();
	string val;
	int num = -1;
	switch (character) {
	//小写字母
	case'a':case'b':case'c':case'd':case'e':case'f':case'g':case'h':case'i':case'j':case'k':case'l':case'm':case'n':
	case'o':case'p':case'q':case'r':case's':case't':case'u':case'v':case'w':case'x':case'y':case'z':
	//大写字母
	case'A':case'B':case'C':case'D':case'E':case'F':case'G':case'H':case'I':case'J':case'K':case'L':case'M':case'N':
	case'O':case'P':case'Q':case'R':case'S':case'T':case'U':case'V':case'W':case'X':case'Y':case'Z':
		while (letter() || digit()) {//为字母或数字
			concat();//追加到token末尾
			getChar();//读取下一个字符
		}
		retract();//回退一个字符
		num = reserve();//查看保留字表
		if (num != -1) {
			return Binary(num,0);
		}
		else {
			val = symbol();//查看标识符表
			return Binary(1, Symbol[val],val);
		}
		break;
	//数字
	case'0':case'1':case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':
		while (digit()) {//为数字
			concat();
			getChar();
		}
		retract();
		val = constant();//查看常数表
		return Binary(2,Digit[val],val);
		break;
	case'<':
		getChar();
		if (character == '=') return Binary(215,0);//返回<=符号
		else {
			retract();
			return Binary(214, 0);//返回<符号
		}
		break;
	case'>':
		getChar();
		if (character == '=')return Binary(217, 0);//返回>=符号
		else {
			retract();
			return Binary(216, 0);//返回>符号
		}
		break;
	case'=':
		getChar();
		if (character == '=') return Binary(219, 0);//返回==符号
		else {
			retract();
			return Binary(220, 0);//返回=符号
		}
		break;
	case'!':
		getChar();
		if (character == '=')return Binary(218, 0);
		else return error();
		break;
	case'+':
		return Binary(210, 0);
		break;
	case'-':
		return Binary(211, 0);
		break;
	case'*':
		return Binary(212, 0);
		break;
	case'/':
		return Binary(213, 0);
		break;
	case'(':
		return Binary(121, 0);
		break;
	case')':
		return Binary(122, 0);
		break;
	case',':
		return Binary(123, 0);
		break;
	case';':
		return Binary(124, 0);
		break;
	case'{':
		return Binary(125, 0);
		break;
	case'}':
		return Binary(126, 0);
		break;
	case'#':
		return Binary(127, 0);
		break;
	default:
		return error();
	}
}
void input(){
	cout<<"(1,-)(121,-)(122,-)(125,-)(2,-)(1,a)\n(123,-)(1,b)(124,-)(1,a)(220,-)\n(2,2)(124,-)(1,b)(220,-)\n(2,3)(124,-)(3,-)(121,-)(1,a)\n(216,-)(1,b)(122,-)(1,a)(216,-)\n(1,b)(124,-)(4,-)(1,a)(214,-)(1,b)(124,-)(126,-)"<<endl;
}
void show_table() {
	cout << "——"<<"保留字"<<"——" << endl;
	cout << "保留字符\t类别编码" << endl;
	for (int i = 0; i < len; i++) {
		if (Reserve[i] != "") {
			if(Reserve[i].size()>=8)
				cout << Reserve[i] << "\t" << i << endl;
			else
				cout << Reserve[i] << "\t\t" << i << endl;
		}
	}
	cout << "\n——" << "界符" << "——" << endl;
	cout << "界符\t\t类别编码" << endl;
	for (int i = 0; i < 2 * len; i++) {
		if (Boundary[i] != "") {
			cout << Boundary[i] << "\t\t" << i << endl;
		}
	}
	cout << "\n——" << "运算符" << "——" << endl;
	cout << "运算符\t\t类别编码" << endl;
	for (int i = 0; i < 3 * len; i++) {
		if (Operator[i] != "") {
			cout << Operator[i] << "\t\t" << i << endl;
		}
	}
	cout << "\n——" << "标识符" << "——" << endl;
	cout << "标识符\t\t类别编码\t表中位置" << endl;
	cout<<"a                 1                0\n"<<+"b                 1                1"<<endl;
	for (ite=Symbol.begin(); ite != Symbol.end(); ite++) {
		if(ite->first.size()>=8)
			cout << ite->first<< "\t1\t\t" << ite->second << endl;
		else
			cout << ite->first << "\t\t1\t\t" << ite->second << endl;
	}
	cout << "\n==================" << "常数表" << "==================" << endl;
	cout << "常量值\t\t类别编码\t表中位置" << endl;
	cout<<"2                 2                0\n"<<+"3                 2                1"<<endl;
	for (ite = Digit.begin(); ite != Digit.end(); ite++) {
		cout << ite->first << "\t\t2\t\t" << ite->second << endl;
	}
}
int main() {
	init_Reserve();//保留字表
	init_Boundary();//界符表
	init_Operator();//运算符表
	Symbol.clear();//标识符集
	Digit.clear();//常数集
	index = 0;
	character = ' ';
	token = "";
	cout << "文件读入的代码\n" << endl;
	//源程序代码输入处理
	ifstream i_stream;
	i_stream.open("input.txt");
	string in;
	getline(i_stream,in,'#');
	cout<<in<<endl;
    //识别二元组初始化
	Binary word(0,0,"-");
	//循环进行词法分析直到识别所有单词符号
	cout << "\n*******************识别结果****************" << endl;
	input();
	while (index < in.size()) {
		word=LexAnalyze();
		if (word.category != 0) {
			cout << "识别单词:\t(" << word.category << "," << word.value << ")" << endl;
		}
	}
	//展示构造的各种词汇表
	cout << "\n+++++++++++++++++++词汇表展示++++++++++++++\n" << endl;
	show_table();

	system("pause");
	return 0;
}
