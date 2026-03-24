extern int my_printf(const char *fmt, ...);

int main()
{
    char ch1 = 'Q';
    char* str1 = "i am cockblock";
    my_printf("hello world! %c %s", ch1, str1);

    return 0;
}