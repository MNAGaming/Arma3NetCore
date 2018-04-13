using System;
using System.Runtime.InteropServices;
using System.Text;

namespace Arma3NetLinuxConsoleSimulator
{
    class Program
    {
        [DllImport(@"..\..\Arma3Net.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern void RVExtension(StringBuilder output, int outputSize, string function);



        static void Main(string[] args)
        {
            StringBuilder output = new StringBuilder(4096);
            RVExtension(output, output.MaxCapacity, args[0]);

            Console.WriteLine("Execute: " + args[0]);
            Console.WriteLine("-Result: " + output.ToString());
            //lstResult.SelectedIndex = lstResult.Items.Count - 1;
            
            //Console.WriteLine("Hello World!");
        }
    }
}
