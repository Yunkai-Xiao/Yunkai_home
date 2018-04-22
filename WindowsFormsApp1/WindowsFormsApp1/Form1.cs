using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Printing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            PrintDocument printer = new PrintDocument();
            printer.PrinterFont = new Font("Verdana", 18);

            printer.TextToPrint = " Hello World";
            System.Drawing.Printing.PrinterSettings newSettings = new System.Drawing.Printing.PrinterSettings();
            printer.PrinterSettings.PrinterName = "HP209535 (HP Photosmart 7510 series)";
            printer.Print();
        }
    }
}
