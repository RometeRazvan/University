namespace LabCSharp_V3
{
    partial class Form2
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
            this.tabelCazuri = new System.Windows.Forms.DataGridView();
            this.tabelDonatii = new System.Windows.Forms.DataGridView();
            this.textNume = new System.Windows.Forms.TextBox();
            this.textAdresa = new System.Windows.Forms.TextBox();
            this.textNumar = new System.Windows.Forms.TextBox();
            this.textSuma = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.buttonClear = new System.Windows.Forms.Button();
            this.buttonAdauga = new System.Windows.Forms.Button();
            this.buttonLogOut = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.textCauta = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.tabelCazuri)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tabelDonatii)).BeginInit();
            this.SuspendLayout();
            // 
            // tabelCazuri
            // 
            this.tabelCazuri.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.tabelCazuri.Location = new System.Drawing.Point(13, 13);
            this.tabelCazuri.Name = "tabelCazuri";
            this.tabelCazuri.Size = new System.Drawing.Size(480, 213);
            this.tabelCazuri.TabIndex = 0;
            // 
            // tabelDonatii
            // 
            this.tabelDonatii.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.tabelDonatii.Location = new System.Drawing.Point(13, 232);
            this.tabelDonatii.Name = "tabelDonatii";
            this.tabelDonatii.Size = new System.Drawing.Size(480, 206);
            this.tabelDonatii.TabIndex = 1;
            this.tabelDonatii.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.tabelDonatii_CellContentClick);
            // 
            // textNume
            // 
            this.textNume.Location = new System.Drawing.Point(688, 13);
            this.textNume.Name = "textNume";
            this.textNume.Size = new System.Drawing.Size(100, 20);
            this.textNume.TabIndex = 2;
            // 
            // textAdresa
            // 
            this.textAdresa.Location = new System.Drawing.Point(688, 40);
            this.textAdresa.Name = "textAdresa";
            this.textAdresa.Size = new System.Drawing.Size(100, 20);
            this.textAdresa.TabIndex = 3;
            // 
            // textNumar
            // 
            this.textNumar.Location = new System.Drawing.Point(687, 67);
            this.textNumar.Name = "textNumar";
            this.textNumar.Size = new System.Drawing.Size(100, 20);
            this.textNumar.TabIndex = 4;
            // 
            // textSuma
            // 
            this.textSuma.Location = new System.Drawing.Point(686, 94);
            this.textSuma.Name = "textSuma";
            this.textSuma.Size = new System.Drawing.Size(100, 20);
            this.textSuma.TabIndex = 5;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(641, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 13);
            this.label1.TabIndex = 6;
            this.label1.Text = "Nume :";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(636, 47);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(46, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "Adresa :";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(604, 74);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(77, 13);
            this.label3.TabIndex = 8;
            this.label3.Text = "Numar Telefon";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(645, 100);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(40, 13);
            this.label4.TabIndex = 9;
            this.label4.Text = "Suma :";
            // 
            // buttonClear
            // 
            this.buttonClear.Location = new System.Drawing.Point(711, 142);
            this.buttonClear.Name = "buttonClear";
            this.buttonClear.Size = new System.Drawing.Size(75, 23);
            this.buttonClear.TabIndex = 10;
            this.buttonClear.Text = "Clear";
            this.buttonClear.UseVisualStyleBackColor = true;
            this.buttonClear.Click += new System.EventHandler(this.buttonClear_Click);
            // 
            // buttonAdauga
            // 
            this.buttonAdauga.Location = new System.Drawing.Point(610, 142);
            this.buttonAdauga.Name = "buttonAdauga";
            this.buttonAdauga.Size = new System.Drawing.Size(75, 23);
            this.buttonAdauga.TabIndex = 11;
            this.buttonAdauga.Text = "Adauga";
            this.buttonAdauga.UseVisualStyleBackColor = true;
            this.buttonAdauga.Click += new System.EventHandler(this.buttonAdauga_Click);
            // 
            // buttonLogOut
            // 
            this.buttonLogOut.Location = new System.Drawing.Point(713, 415);
            this.buttonLogOut.Name = "buttonLogOut";
            this.buttonLogOut.Size = new System.Drawing.Size(75, 23);
            this.buttonLogOut.TabIndex = 12;
            this.buttonLogOut.Text = "Log Out";
            this.buttonLogOut.UseVisualStyleBackColor = true;
            this.buttonLogOut.Click += new System.EventHandler(this.buttonLogOut_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(605, 232);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(75, 23);
            this.button4.TabIndex = 13;
            this.button4.Text = "Cauta";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // textCauta
            // 
            this.textCauta.Location = new System.Drawing.Point(499, 232);
            this.textCauta.Name = "textCauta";
            this.textCauta.Size = new System.Drawing.Size(100, 20);
            this.textCauta.TabIndex = 14;
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.textCauta);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.buttonLogOut);
            this.Controls.Add(this.buttonAdauga);
            this.Controls.Add(this.buttonClear);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textSuma);
            this.Controls.Add(this.textNumar);
            this.Controls.Add(this.textAdresa);
            this.Controls.Add(this.textNume);
            this.Controls.Add(this.tabelDonatii);
            this.Controls.Add(this.tabelCazuri);
            this.Name = "Form2";
            this.Text = "Form2";
            this.Load += new System.EventHandler(this.Form2_Load);
            ((System.ComponentModel.ISupportInitialize)(this.tabelCazuri)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tabelDonatii)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView tabelCazuri;
        private System.Windows.Forms.DataGridView tabelDonatii;
        private System.Windows.Forms.TextBox textNume;
        private System.Windows.Forms.TextBox textAdresa;
        private System.Windows.Forms.TextBox textNumar;
        private System.Windows.Forms.TextBox textSuma;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button buttonClear;
        private System.Windows.Forms.Button buttonAdauga;
        private System.Windows.Forms.Button buttonLogOut;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.TextBox textCauta;
    }
}