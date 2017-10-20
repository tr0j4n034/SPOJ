using System;

namespace Practice
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; i ++) {
                int N = int.Parse(Console.ReadLine());
                if (N == 0) {
                    Console.WriteLine("North");
                    continue;
                }
                int now = 0, step = 1;
                int result = 0;
                while (true) {
                    if (now + step > N) {
                        result = 1;
                        break;
                    }
                    now += step;
                    if (now + step > N) {
                        result = 2;
                        break;
                    }
                    now += step;
                    if (now + step + 1 > N) {
                        result = 3;
                        break;
                    }
                    now += step + 1;
                    if (now + step + 1 > N) {
                        result = 4;
                        break;
                    }
                    now += step + 1;
                    step += 2;
                }
                string output;
                if (result == 1) {
                    output = "North";
                }
                else if (result == 2) {
                    output = "East";
                }
                else if (result == 3) {
                    output = "South";
                }
                else {
                    output = "West";
                }
                Console.WriteLine(output);
            }
        }
    }
}
