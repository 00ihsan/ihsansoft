using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Pincode_Generator
{

    public partial class Form1 : Form
    {
        private bool showPIN = false;
        private bool copyPIN = false;
        private bool pinAvailable = false;
        private readonly char mask = '#';
        private readonly char no_mask = '0';
        private int pin = 0000;

        private readonly string[] errorarray = { "0000", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999", "1234", "12345", "123456", "123467", "12345678", "123456789" };

        public Form1()
        {
            pinAvailable = false;
            showPIN = false;
            copyPIN = false;
            InitializeComponent();
            InitListBox();
            cbCopyPIN.Checked = false;
            cbShowPIN.Checked = false;
            no_mask = tbOutputPIN.PasswordChar;
            tbOutputPIN.PasswordChar = mask;
            timerCheckUI.Start();
        }

        private void InitListBox()
        {
            lbDigits.Items.Clear();
            for (int num = 4; num < 10; num++)
            {
                lbDigits.Items.Add(num + " digit's");
            }
        }

        private void btGen_Click(object sender, EventArgs e)
        {

            if (lbDigits.SelectedIndex != -1)
            {   
                int minDigits = 0;
                int minValue = 1;
                int maxValue = 0;
                bool success = Int32.TryParse(lbDigits.SelectedItem.ToString().Substring(0, lbDigits.SelectedItem.ToString().IndexOf("d")), out minDigits);
                if (success && minDigits != 0)
                {
                    for (int minV = 1; minV < minDigits; minV++)
                    {
                        minValue *= 10;
                    }

                    if (minValue != 0)
                    {
                        maxValue = minValue * 10 - 1;
                    }

                    Random rand = new Random();
                    pin = rand.Next(minValue, maxValue);
                    foreach (String element in errorarray)
                    {
                        if (pin.ToString() == element)
                        {
                            pin = rand.Next(minValue, maxValue);
                        }
                    }
                    pinAvailable = true;
                    tbOutputPIN.Text = pin.ToString();
                }
            }
        }

        private void timerCheckUI_Tick(object sender, EventArgs e)
        {
            showPIN = cbShowPIN.Checked;
            copyPIN = cbCopyPIN.Checked;

            if (showPIN)
            {
                tbOutputPIN.PasswordChar = no_mask;
            }
            if (!showPIN)
            {
                tbOutputPIN.PasswordChar = mask;
            }

            if (copyPIN)
            {
                if (pinAvailable)
                {
                    Clipboard.SetText(pin.ToString());
                    pinAvailable = false;
                }
            }

            if (lbDigits.SelectedIndex == -1)
            {
                btGen.Enabled = false;
            }

            if (lbDigits.SelectedIndex != -1)
            {
                btGen.Enabled = true;
            }
        }
    }
}
