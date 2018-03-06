namespace SelectiveBlurTest
{
    unsafe partial class FrmTest
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FrmTest));
            this.CmdOpen = new System.Windows.Forms.Button();
            this.CmdSave = new System.Windows.Forms.Button();
            this.PicDest = new System.Windows.Forms.PictureBox();
            this.PicSrc = new System.Windows.Forms.PictureBox();
            this.LblInfo = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.Radius = new System.Windows.Forms.HScrollBar();
            this.LblRadius = new System.Windows.Forms.Label();
            this.LblThreshold = new System.Windows.Forms.Label();
            this.Threshold = new System.Windows.Forms.HScrollBar();
            this.阈值 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.PicDest)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.PicSrc)).BeginInit();
            this.SuspendLayout();
            // 
            // CmdOpen
            // 
            this.CmdOpen.Location = new System.Drawing.Point(4, 7);
            this.CmdOpen.Name = "CmdOpen";
            this.CmdOpen.Size = new System.Drawing.Size(75, 31);
            this.CmdOpen.TabIndex = 21;
            this.CmdOpen.Text = "Open image";
            this.CmdOpen.UseVisualStyleBackColor = true;
            this.CmdOpen.Click += new System.EventHandler(this.CmdOpen_Click);
            // 
            // CmdSave
            // 
            this.CmdSave.Location = new System.Drawing.Point(85, 7);
            this.CmdSave.Name = "CmdSave";
            this.CmdSave.Size = new System.Drawing.Size(75, 31);
            this.CmdSave.TabIndex = 35;
            this.CmdSave.Text = "Save image";
            this.CmdSave.UseVisualStyleBackColor = true;
            this.CmdSave.Click += new System.EventHandler(this.CmdSave_Click);
            // 
            // PicDest
            // 
            this.PicDest.Image = ((System.Drawing.Image)(resources.GetObject("PicDest.Image")));
            this.PicDest.Location = new System.Drawing.Point(617, 80);
            this.PicDest.Name = "PicDest";
            this.PicDest.Size = new System.Drawing.Size(550, 574);
            this.PicDest.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.PicDest.TabIndex = 34;
            this.PicDest.TabStop = false;
            // 
            // PicSrc
            // 
            this.PicSrc.Image = ((System.Drawing.Image)(resources.GetObject("PicSrc.Image")));
            this.PicSrc.Location = new System.Drawing.Point(12, 80);
            this.PicSrc.Name = "PicSrc";
            this.PicSrc.Size = new System.Drawing.Size(550, 574);
            this.PicSrc.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.PicSrc.TabIndex = 33;
            this.PicSrc.TabStop = false;
            // 
            // LblInfo
            // 
            this.LblInfo.AutoSize = true;
            this.LblInfo.Location = new System.Drawing.Point(30, 55);
            this.LblInfo.Name = "LblInfo";
            this.LblInfo.Size = new System.Drawing.Size(0, 13);
            this.LblInfo.TabIndex = 36;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(184, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(43, 13);
            this.label1.TabIndex = 37;
            this.label1.Text = "Radius:";
            // 
            // Radius
            // 
            this.Radius.Location = new System.Drawing.Point(235, 12);
            this.Radius.Maximum = 127;
            this.Radius.Minimum = 1;
            this.Radius.Name = "Radius";
            this.Radius.Size = new System.Drawing.Size(327, 20);
            this.Radius.TabIndex = 38;
            this.Radius.Value = 10;
            this.Radius.Scroll += new System.Windows.Forms.ScrollEventHandler(this.Radius_Scroll);
            // 
            // LblRadius
            // 
            this.LblRadius.AutoSize = true;
            this.LblRadius.Location = new System.Drawing.Point(578, 15);
            this.LblRadius.Name = "LblRadius";
            this.LblRadius.Size = new System.Drawing.Size(19, 13);
            this.LblRadius.TabIndex = 39;
            this.LblRadius.Text = "10";
            // 
            // LblThreshold
            // 
            this.LblThreshold.AutoSize = true;
            this.LblThreshold.Location = new System.Drawing.Point(1013, 15);
            this.LblThreshold.Name = "LblThreshold";
            this.LblThreshold.Size = new System.Drawing.Size(19, 13);
            this.LblThreshold.TabIndex = 42;
            this.LblThreshold.Text = "16";
            // 
            // Threshold
            // 
            this.Threshold.Location = new System.Drawing.Point(679, 12);
            this.Threshold.Maximum = 255;
            this.Threshold.Name = "Threshold";
            this.Threshold.Size = new System.Drawing.Size(318, 20);
            this.Threshold.TabIndex = 41;
            this.Threshold.Value = 16;
            this.Threshold.Scroll += new System.Windows.Forms.ScrollEventHandler(this.Threshold_Scroll);
            // 
            // 阈值
            // 
            this.阈值.AutoSize = true;
            this.阈值.Location = new System.Drawing.Point(619, 15);
            this.阈值.Name = "阈值";
            this.阈值.Size = new System.Drawing.Size(57, 13);
            this.阈值.TabIndex = 40;
            this.阈值.Text = "Threshold:";
            // 
            // FrmTest
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1179, 683);
            this.Controls.Add(this.LblThreshold);
            this.Controls.Add(this.Threshold);
            this.Controls.Add(this.阈值);
            this.Controls.Add(this.LblRadius);
            this.Controls.Add(this.Radius);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.LblInfo);
            this.Controls.Add(this.CmdSave);
            this.Controls.Add(this.PicDest);
            this.Controls.Add(this.PicSrc);
            this.Controls.Add(this.CmdOpen);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MinimizeBox = false;
            this.Name = "FrmTest";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Selective Blur Test";
            this.Load += new System.EventHandler(this.FrmTest_Load);
            ((System.ComponentModel.ISupportInitialize)(this.PicDest)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.PicSrc)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button CmdOpen;
        private System.Windows.Forms.PictureBox PicSrc;
        private System.Windows.Forms.PictureBox PicDest;
        private System.Windows.Forms.Button CmdSave;
        private System.Windows.Forms.Label LblInfo;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.HScrollBar Radius;
        private System.Windows.Forms.Label LblRadius;
        private System.Windows.Forms.Label LblThreshold;
        private System.Windows.Forms.HScrollBar Threshold;
        private System.Windows.Forms.Label 阈值;

    }
}

