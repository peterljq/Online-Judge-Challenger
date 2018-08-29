//丙增增

#define 双浮点数 double
#define 整数 int
#define 被赋值为 =
#define 圆周率 3.141592653589793
#define 主函数 main
#define 无返回值 void
#define 输出 cout
#define 换行 endl
#define 加 +

using namespace std;

无返回值 打印(双浮点数 甲);
整数 主函数();

无返回值 打印(双浮点数 甲){
    输出 << 甲 << 换行;
}

整数 主函数(){
    双浮点数 甲 被赋值为 圆周率;
    双浮点数 乙 被赋值为 1.212345;
    打印(甲);
    打印(乙);
    双浮点数 丙 被赋值为 甲 加 乙;
    打印(丙);
}
