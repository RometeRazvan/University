namespace Faza2.Windows
{
    partial class TerminalApp
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
            this.locTable = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.numeText = new System.Windows.Forms.TextBox();
            this.telefonText = new System.Windows.Forms.TextBox();
            this.emailText = new System.Windows.Forms.TextBox();
            this.rezervaBtn = new System.Windows.Forms.Button();
            this.anuleazaBtn = new System.Windows.Forms.Button();
            this.modificaBtn = new System.Windows.Forms.Button();
            this.titluOperLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.locTable)).BeginInit();
            this.SuspendLayout();
            // 
            // locTable
            // 
            this.locTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.locTable.Location = new System.Drawing.Point(13, 13);
            this.locTable.Name = "locTable";
            this.locTable.Size = new System.Drawing.Size(308, 425);
            this.locTable.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(503, 142);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Nume: ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(495, 168);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Telefon: ";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(506, 194);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(38, 13);
            this.label3.TabIndex = 3;
            this.label3.Text = "Email: ";
            // 
            // numeText
            // 
            this.numeText.Location = new System.Drawing.Point(550, 139);
            this.numeText.Name = "numeText";
            this.numeText.Size = new System.Drawing.Size(141, 20);
            this.numeText.TabIndex = 4;
            // 
            // telefonText
            // 
            this.telefonText.Location = new System.Drawing.Point(550, 165);
            this.telefonText.Name = "telefonText";
            this.telefonText.Size = new System.Drawing.Size(141, 20);
            this.telefonText.TabIndex = 5;
            // 
            // emailText
            // 
            this.emailText.Location = new System.Drawing.Point(550, 191);
            this.emailText.Name = "emailText";
            this.emailText.Size = new System.Drawing.Size(141, 20);
            this.emailText.TabIndex = 6;
            // 
            // rezervaBtn
            // 
            this.rezervaBtn.Location = new System.Drawing.Point(469, 224);
            this.rezervaBtn.Name = "rezervaBtn";
            this.rezervaBtn.Size = new System.Drawing.Size(75, 23);
            this.rezervaBtn.TabIndex = 7;
            this.rezervaBtn.Text = "Rezerva";
            this.rezervaBtn.UseVisualStyleBackColor = true;
            this.rezervaBtn.Click += new System.EventHandler(this.rezervaBtn_Click);
            // 
            // anuleazaBtn
            // 
            this.anuleazaBtn.Location = new System.Drawing.Point(550, 224);
            this.anuleazaBtn.Name = "anuleazaBtn";
            this.anuleazaBtn.Size = new System.Drawing.Size(75, 23);
            this.anuleazaBtn.TabIndex = 8;
            this.anuleazaBtn.Text = "Anuleaza";
            this.anuleazaBtn.UseVisualStyleBackColor = true;
            this.anuleazaBtn.Click += new System.EventHandler(this.anuleazaBtn_Click);
            // 
            // modificaBtn
            // 
            this.modificaBtn.Location = new System.Drawing.Point(631, 224);
            this.modificaBtn.Name = "modificaBtn";
            this.modificaBtn.Size = new System.Drawing.Size(75, 23);
            this.modificaBtn.TabIndex = 9;
            this.modificaBtn.Text = "Modifica";
            this.modificaBtn.UseVisualStyleBackColor = true;
            this.modificaBtn.Click += new System.EventHandler(this.modificaBtn_Click);
            // 
            // titluOperLabel
            // 
            this.titluOperLabel.AutoSize = true;
            this.titluOperLabel.Location = new System.Drawing.Point(495, 13);
            this.titluOperLabel.Name = "titluOperLabel";
            this.titluOperLabel.Size = new System.Drawing.Size(0, 13);
            this.titluOperLabel.TabIndex = 10;
            this.titluOperLabel.Click += new System.EventHandler(this.label4_Click);
            // 
            // TerminalApp
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.titluOperLabel);
            this.Controls.Add(this.modificaBtn);
            this.Controls.Add(this.anuleazaBtn);
            this.Controls.Add(this.rezervaBtn);
            this.Controls.Add(this.emailText);
            this.Controls.Add(this.telefonText);
            this.Controls.Add(this.numeText);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.locTable);
            this.Name = "TerminalApp";
            this.Text = "TerminalApp";
            this.Load += new System.EventHandler(this.TerminalApp_Load);
            ((System.ComponentModel.ISupportInitialize)(this.locTable)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView locTable;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox numeText;
        private System.Windows.Forms.TextBox telefonText;
        private System.Windows.Forms.TextBox emailText;
        private System.Windows.Forms.Button rezervaBtn;
        private System.Windows.Forms.Button anuleazaBtn;
        private System.Windows.Forms.Button modificaBtn;
        private System.Windows.Forms.Label titluOperLabel;
    }
}