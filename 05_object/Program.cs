using System;

namespace _05_object
{
    class Program
    {
        static void Main(string[] args)
        {
            // 모든 데이터 형식은 object 를 상속 받는다.
            // 어떤 형식의 데이터라도 object에 담아 처리할 수 있다.
            object a = 123;
            object b = 3.14159265358979323846m;
            object c = true;
            object d = "안녕하세요.";

            Console.WriteLine(a);
            Console.WriteLine(b);
            Console.WriteLine(c);
            Console.WriteLine(d);
        }
    }
}
