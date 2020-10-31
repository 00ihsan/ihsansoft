namespace Pincode_Generator
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.btGen = new System.Windows.Forms.Button();
            this.lbDigits = new System.Windows.Forms.ListBox();
            this.tbOutputPIN = new System.Windows.Forms.TextBox();
            this.timerCheckUI = new System.Windows.Forms.Timer(this.components);
            this.cbShowPIN = new System.Windows.Forms.CheckBox();
            this.cbCopyPIN = new System.Windows.Forms.CheckBox();
            this.label3 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 11);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(128, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "Number of digits:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(168, 43);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(150, 20);
            this.label2.TabIndex = 1;
            this.label2.Text = "Generated pincode:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(168, 11);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(60, 20);
            this.label4.TabIndex = 3;
            this.label4.Text = "Status:";
            // 
            // btGen
            // 
            this.btGen.Location = new System.Drawing.Point(315, 3);
            this.btGen.Name = "btGen";
            this.btGen.Size = new System.Drawing.Size(93, 32);
            this.btGen.TabIndex = 4;
            this.btGen.Text = "Generate!";
            this.btGen.UseVisualStyleBackColor = true;
            this.btGen.Click += new System.EventHandler(this.btGen_Click);
            // 
            // lbDigits
            // 
            this.lbDigits.FormattingEnabled = true;
            this.lbDigits.ItemHeight = 20;
            this.lbDigits.Location = new System.Drawing.Point(16, 39);
            this.lbDigits.Name = "lbDigits";
            this.lbDigits.Size = new System.Drawing.Size(93, 24);
            this.lbDigits.TabIndex = 5;
            // 
            // tbOutputPIN
            // 
            this.tbOutputPIN.Location = new System.Drawing.Point(315, 40);
            this.tbOutputPIN.Name = "tbOutputPIN";
            this.tbOutputPIN.Size = new System.Drawing.Size(93, 26);
            this.tbOutputPIN.TabIndex = 6;
            // 
            // timerCheckUI
            // 
            this.timerCheckUI.Interval = 10;
            this.timerCheckUI.Tick += new System.EventHandler(this.timerCheckUI_Tick);
            // 
            // cbShowPIN
            // 
            this.cbShowPIN.AutoSize = true;
            this.cbShowPIN.Location = new System.Drawing.Point(16, 69);
            this.cbShowPIN.Name = "cbShowPIN";
            this.cbShowPIN.Size = new System.Drawing.Size(135, 24);
            this.cbShowPIN.TabIndex = 7;
            this.cbShowPIN.Text = "Show pincode";
            this.cbShowPIN.UseVisualStyleBackColor = true;
            // 
            // cbCopyPIN
            // 
            this.cbCopyPIN.AutoSize = true;
            this.cbCopyPIN.Location = new System.Drawing.Point(172, 69);
            this.cbCopyPIN.Name = "cbCopyPIN";
            this.cbCopyPIN.Size = new System.Drawing.Size(131, 24);
            this.cbCopyPIN.TabIndex = 8;
            this.cbCopyPIN.Text = "Copy pincode";
            this.cbCopyPIN.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(130, 96);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(141, 20);
            this.label3.TabIndex = 10;
            this.label3.Text = "(C) Ihsansoft 2020";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(415, 117);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.cbCopyPIN);
            this.Controls.Add(this.cbShowPIN);
            this.Controls.Add(this.tbOutputPIN);
            this.Controls.Add(this.lbDigits);
            this.Controls.Add(this.btGen);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Pincode Generator";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btGen;
        private System.Windows.Forms.ListBox lbDigits;
        private System.Windows.Forms.TextBox tbOutputPIN;
        private System.Windows.Forms.Timer timerCheckUI;
        private System.Windows.Forms.CheckBox cbShowPIN;
        private System.Windows.Forms.CheckBox cbCopyPIN;
        private System.Windows.Forms.Label label3;
    }
}

