namespace Faza2.Windows
{
    partial class ManagerApp
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
            this.piesaBox = new System.Windows.Forms.ComboBox();
            this.startButton = new System.Windows.Forms.Button();
            this.stopButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.closeBtn = new System.Windows.Forms.Button();
            this.spectatorTable = new System.Windows.Forms.DataGridView();
            this.locuriTable = new System.Windows.Forms.DataGridView();
            this.anuleazaBtn = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.spectatorTable)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.locuriTable)).BeginInit();
            this.SuspendLayout();
            // 
            // piesaBox
            // 
            this.piesaBox.FormattingEnabled = true;
            this.piesaBox.Location = new System.Drawing.Point(91, 12);
            this.piesaBox.Name = "piesaBox";
            this.piesaBox.Size = new System.Drawing.Size(142, 21);
            this.piesaBox.TabIndex = 0;
            // 
            // startButton
            // 
            this.startButton.Location = new System.Drawing.Point(77, 39);
            this.startButton.Name = "startButton";
            this.startButton.Size = new System.Drawing.Size(75, 23);
            this.startButton.TabIndex = 1;
            this.startButton.Text = "Start";
            this.startButton.UseVisualStyleBackColor = true;
            this.startButton.Click += new System.EventHandler(this.startButton_Click);
            // 
            // stopButton
            // 
            this.stopButton.Location = new System.Drawing.Point(158, 39);
            this.stopButton.Name = "stopButton";
            this.stopButton.Size = new System.Drawing.Size(75, 23);
            this.stopButton.TabIndex = 2;
            this.stopButton.Text = "Stop";
            this.stopButton.UseVisualStyleBackColor = true;
            this.stopButton.Click += new System.EventHandler(this.stopButton_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(73, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Alegeti peisa: ";
            // 
            // closeBtn
            // 
            this.closeBtn.Location = new System.Drawing.Point(10, 415);
            this.closeBtn.Name = "closeBtn";
            this.closeBtn.Size = new System.Drawing.Size(75, 23);
            this.closeBtn.TabIndex = 4;
            this.closeBtn.Text = "Close";
            this.closeBtn.UseVisualStyleBackColor = true;
            this.closeBtn.Click += new System.EventHandler(this.closeBtn_Click);
            // 
            // spectatorTable
            // 
            this.spectatorTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.spectatorTable.Location = new System.Drawing.Point(267, 12);
            this.spectatorTable.Name = "spectatorTable";
            this.spectatorTable.Size = new System.Drawing.Size(303, 426);
            this.spectatorTable.TabIndex = 5;
            this.spectatorTable.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.spectatorTable_CellContentClick);
            this.spectatorTable.SelectionChanged += new System.EventHandler(this.spectatorTable_SelectionChanged);
            // 
            // locuriTable
            // 
            this.locuriTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.locuriTable.Location = new System.Drawing.Point(576, 12);
            this.locuriTable.Name = "locuriTable";
            this.locuriTable.Size = new System.Drawing.Size(212, 426);
            this.locuriTable.TabIndex = 6;
            // 
            // anuleazaBtn
            // 
            this.anuleazaBtn.Location = new System.Drawing.Point(158, 201);
            this.anuleazaBtn.Name = "anuleazaBtn";
            this.anuleazaBtn.Size = new System.Drawing.Size(75, 38);
            this.anuleazaBtn.TabIndex = 7;
            this.anuleazaBtn.Text = "Anuleaza Rezervare";
            this.anuleazaBtn.UseVisualStyleBackColor = true;
            this.anuleazaBtn.Click += new System.EventHandler(this.anuleazaBtn_Click);
            // 
            // ManagerApp
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.anuleazaBtn);
            this.Controls.Add(this.locuriTable);
            this.Controls.Add(this.spectatorTable);
            this.Controls.Add(this.closeBtn);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.stopButton);
            this.Controls.Add(this.startButton);
            this.Controls.Add(this.piesaBox);
            this.Name = "ManagerApp";
            this.Text = "ManagerApp";
            this.Load += new System.EventHandler(this.ManagerApp_Load);
            ((System.ComponentModel.ISupportInitialize)(this.spectatorTable)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.locuriTable)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox piesaBox;
        private System.Windows.Forms.Button startButton;
        private System.Windows.Forms.Button stopButton;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button closeBtn;
        private System.Windows.Forms.DataGridView spectatorTable;
        private System.Windows.Forms.DataGridView locuriTable;
        private System.Windows.Forms.Button anuleazaBtn;
    }
}