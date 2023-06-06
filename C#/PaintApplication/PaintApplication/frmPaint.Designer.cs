
namespace PaintApplication
{
    partial class frmPaint
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
            this.toolbarPanel = new System.Windows.Forms.Panel();
            this.basePanel = new System.Windows.Forms.Panel();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.penSizeTBar = new System.Windows.Forms.TrackBar();
            this.btnSave = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.toolboxPanel = new System.Windows.Forms.Panel();
            this.btnLine = new System.Windows.Forms.Button();
            this.btnRectangle = new System.Windows.Forms.Button();
            this.btnEllipse = new System.Windows.Forms.Button();
            this.btnPencil = new System.Windows.Forms.Button();
            this.btnEraser = new System.Windows.Forms.Button();
            this.colorPickerPanel = new System.Windows.Forms.Panel();
            this.currentColorPanel = new System.Windows.Forms.Panel();
            this.btnColorPicker = new System.Windows.Forms.Button();
            this.drawArea = new System.Windows.Forms.PictureBox();
            this.colorsPanel1 = new System.Windows.Forms.Panel();
            this.colorsPanel2 = new System.Windows.Forms.Panel();
            this.toolbarPanel.SuspendLayout();
            this.basePanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.penSizeTBar)).BeginInit();
            this.toolboxPanel.SuspendLayout();
            this.colorPickerPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.drawArea)).BeginInit();
            this.SuspendLayout();
            // 
            // toolbarPanel
            // 
            this.toolbarPanel.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(56)))), ((int)(((byte)(56)))));
            this.toolbarPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.toolbarPanel.Controls.Add(this.basePanel);
            this.toolbarPanel.Controls.Add(this.toolboxPanel);
            this.toolbarPanel.Controls.Add(this.colorPickerPanel);
            this.toolbarPanel.Dock = System.Windows.Forms.DockStyle.Top;
            this.toolbarPanel.Location = new System.Drawing.Point(0, 0);
            this.toolbarPanel.Name = "toolbarPanel";
            this.toolbarPanel.Size = new System.Drawing.Size(884, 86);
            this.toolbarPanel.TabIndex = 0;
            // 
            // basePanel
            // 
            this.basePanel.Controls.Add(this.label2);
            this.basePanel.Controls.Add(this.label1);
            this.basePanel.Controls.Add(this.penSizeTBar);
            this.basePanel.Controls.Add(this.btnSave);
            this.basePanel.Controls.Add(this.btnClear);
            this.basePanel.Location = new System.Drawing.Point(-1, 0);
            this.basePanel.Name = "basePanel";
            this.basePanel.Size = new System.Drawing.Size(120, 84);
            this.basePanel.TabIndex = 8;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Verdana", 8F);
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(105, 62);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(14, 13);
            this.label2.TabIndex = 13;
            this.label2.Text = "3";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Verdana", 8F);
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(104, 7);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(21, 13);
            this.label1.TabIndex = 8;
            this.label1.Text = "15";
            // 
            // penSizeTBar
            // 
            this.penSizeTBar.AutoSize = false;
            this.penSizeTBar.Location = new System.Drawing.Point(81, 0);
            this.penSizeTBar.Maximum = 15;
            this.penSizeTBar.Minimum = 3;
            this.penSizeTBar.Name = "penSizeTBar";
            this.penSizeTBar.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.penSizeTBar.Size = new System.Drawing.Size(45, 84);
            this.penSizeTBar.TabIndex = 8;
            this.penSizeTBar.TickStyle = System.Windows.Forms.TickStyle.None;
            this.penSizeTBar.Value = 3;
            this.penSizeTBar.Scroll += new System.EventHandler(this.penSizeTBar_Scroll);
            // 
            // btnSave
            // 
            this.btnSave.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnSave.FlatAppearance.BorderColor = System.Drawing.Color.Silver;
            this.btnSave.FlatAppearance.BorderSize = 2;
            this.btnSave.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DimGray;
            this.btnSave.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Black;
            this.btnSave.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSave.Font = new System.Drawing.Font("Verdana", 8F);
            this.btnSave.ForeColor = System.Drawing.Color.White;
            this.btnSave.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnSave.Location = new System.Drawing.Point(2, 9);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(64, 30);
            this.btnSave.TabIndex = 10;
            this.btnSave.Text = "Save";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // btnClear
            // 
            this.btnClear.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnClear.FlatAppearance.BorderColor = System.Drawing.Color.Silver;
            this.btnClear.FlatAppearance.BorderSize = 2;
            this.btnClear.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DimGray;
            this.btnClear.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Black;
            this.btnClear.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnClear.Font = new System.Drawing.Font("Verdana", 8F);
            this.btnClear.ForeColor = System.Drawing.Color.White;
            this.btnClear.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnClear.Location = new System.Drawing.Point(2, 45);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(64, 30);
            this.btnClear.TabIndex = 12;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // toolboxPanel
            // 
            this.toolboxPanel.Controls.Add(this.btnLine);
            this.toolboxPanel.Controls.Add(this.btnRectangle);
            this.toolboxPanel.Controls.Add(this.btnEllipse);
            this.toolboxPanel.Controls.Add(this.btnPencil);
            this.toolboxPanel.Controls.Add(this.btnEraser);
            this.toolboxPanel.Location = new System.Drawing.Point(122, 1);
            this.toolboxPanel.Name = "toolboxPanel";
            this.toolboxPanel.Size = new System.Drawing.Size(585, 84);
            this.toolboxPanel.TabIndex = 8;
            // 
            // btnLine
            // 
            this.btnLine.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnLine.FlatAppearance.BorderColor = System.Drawing.Color.Silver;
            this.btnLine.FlatAppearance.BorderSize = 2;
            this.btnLine.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DimGray;
            this.btnLine.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Black;
            this.btnLine.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnLine.Font = new System.Drawing.Font("Verdana", 8F);
            this.btnLine.ForeColor = System.Drawing.Color.White;
            this.btnLine.Image = global::PaintApplication.Properties.Resources.straight_line;
            this.btnLine.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.btnLine.Location = new System.Drawing.Point(300, 13);
            this.btnLine.Name = "btnLine";
            this.btnLine.Size = new System.Drawing.Size(83, 57);
            this.btnLine.TabIndex = 7;
            this.btnLine.Text = "Line";
            this.btnLine.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.btnLine.UseVisualStyleBackColor = true;
            this.btnLine.Click += new System.EventHandler(this.btnLine_Click);
            // 
            // btnRectangle
            // 
            this.btnRectangle.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnRectangle.FlatAppearance.BorderColor = System.Drawing.Color.Silver;
            this.btnRectangle.FlatAppearance.BorderSize = 2;
            this.btnRectangle.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DimGray;
            this.btnRectangle.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Black;
            this.btnRectangle.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnRectangle.Font = new System.Drawing.Font("Verdana", 8F);
            this.btnRectangle.ForeColor = System.Drawing.Color.White;
            this.btnRectangle.Image = global::PaintApplication.Properties.Resources.rectangle;
            this.btnRectangle.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.btnRectangle.Location = new System.Drawing.Point(498, 13);
            this.btnRectangle.Name = "btnRectangle";
            this.btnRectangle.Size = new System.Drawing.Size(83, 57);
            this.btnRectangle.TabIndex = 6;
            this.btnRectangle.Text = "Rectangle";
            this.btnRectangle.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.btnRectangle.UseVisualStyleBackColor = true;
            this.btnRectangle.Click += new System.EventHandler(this.btnRectangle_Click);
            // 
            // btnEllipse
            // 
            this.btnEllipse.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnEllipse.FlatAppearance.BorderColor = System.Drawing.Color.Silver;
            this.btnEllipse.FlatAppearance.BorderSize = 2;
            this.btnEllipse.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DimGray;
            this.btnEllipse.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Black;
            this.btnEllipse.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnEllipse.Font = new System.Drawing.Font("Verdana", 8F);
            this.btnEllipse.ForeColor = System.Drawing.Color.White;
            this.btnEllipse.Image = global::PaintApplication.Properties.Resources.ellipse;
            this.btnEllipse.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.btnEllipse.Location = new System.Drawing.Point(399, 13);
            this.btnEllipse.Name = "btnEllipse";
            this.btnEllipse.Size = new System.Drawing.Size(83, 57);
            this.btnEllipse.TabIndex = 5;
            this.btnEllipse.Text = "Ellipse";
            this.btnEllipse.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.btnEllipse.UseVisualStyleBackColor = true;
            this.btnEllipse.Click += new System.EventHandler(this.btnEllipse_Click);
            // 
            // btnPencil
            // 
            this.btnPencil.BackColor = System.Drawing.Color.Black;
            this.btnPencil.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnPencil.FlatAppearance.BorderColor = System.Drawing.Color.Silver;
            this.btnPencil.FlatAppearance.BorderSize = 2;
            this.btnPencil.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DimGray;
            this.btnPencil.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Black;
            this.btnPencil.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnPencil.Font = new System.Drawing.Font("Verdana", 8F, System.Drawing.FontStyle.Bold);
            this.btnPencil.ForeColor = System.Drawing.Color.White;
            this.btnPencil.Image = global::PaintApplication.Properties.Resources.pencil;
            this.btnPencil.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.btnPencil.Location = new System.Drawing.Point(201, 13);
            this.btnPencil.Name = "btnPencil";
            this.btnPencil.Size = new System.Drawing.Size(83, 57);
            this.btnPencil.TabIndex = 3;
            this.btnPencil.Text = "Pencil";
            this.btnPencil.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.btnPencil.UseVisualStyleBackColor = false;
            this.btnPencil.Click += new System.EventHandler(this.btnPencil_Click);
            // 
            // btnEraser
            // 
            this.btnEraser.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnEraser.FlatAppearance.BorderColor = System.Drawing.Color.Silver;
            this.btnEraser.FlatAppearance.BorderSize = 2;
            this.btnEraser.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DimGray;
            this.btnEraser.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Black;
            this.btnEraser.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnEraser.Font = new System.Drawing.Font("Verdana", 8F);
            this.btnEraser.ForeColor = System.Drawing.Color.White;
            this.btnEraser.Image = global::PaintApplication.Properties.Resources.eraser;
            this.btnEraser.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.btnEraser.Location = new System.Drawing.Point(102, 13);
            this.btnEraser.Name = "btnEraser";
            this.btnEraser.Size = new System.Drawing.Size(83, 57);
            this.btnEraser.TabIndex = 4;
            this.btnEraser.Text = "Eraser";
            this.btnEraser.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.btnEraser.UseVisualStyleBackColor = true;
            this.btnEraser.Click += new System.EventHandler(this.btnEraser_Click);
            // 
            // colorPickerPanel
            // 
            this.colorPickerPanel.Controls.Add(this.currentColorPanel);
            this.colorPickerPanel.Controls.Add(this.btnColorPicker);
            this.colorPickerPanel.Location = new System.Drawing.Point(722, 0);
            this.colorPickerPanel.Name = "colorPickerPanel";
            this.colorPickerPanel.Size = new System.Drawing.Size(149, 84);
            this.colorPickerPanel.TabIndex = 9;
            // 
            // currentColorPanel
            // 
            this.currentColorPanel.BackColor = System.Drawing.Color.Black;
            this.currentColorPanel.Location = new System.Drawing.Point(2, 28);
            this.currentColorPanel.Name = "currentColorPanel";
            this.currentColorPanel.Size = new System.Drawing.Size(40, 35);
            this.currentColorPanel.TabIndex = 0;
            // 
            // btnColorPicker
            // 
            this.btnColorPicker.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnColorPicker.FlatAppearance.BorderColor = System.Drawing.Color.Silver;
            this.btnColorPicker.FlatAppearance.BorderSize = 2;
            this.btnColorPicker.FlatAppearance.MouseDownBackColor = System.Drawing.Color.DimGray;
            this.btnColorPicker.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Black;
            this.btnColorPicker.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnColorPicker.Font = new System.Drawing.Font("Verdana", 8F);
            this.btnColorPicker.ForeColor = System.Drawing.Color.White;
            this.btnColorPicker.Image = global::PaintApplication.Properties.Resources.color_circle;
            this.btnColorPicker.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.btnColorPicker.Location = new System.Drawing.Point(58, 13);
            this.btnColorPicker.Name = "btnColorPicker";
            this.btnColorPicker.Size = new System.Drawing.Size(88, 57);
            this.btnColorPicker.TabIndex = 1;
            this.btnColorPicker.Text = "More Colors";
            this.btnColorPicker.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.btnColorPicker.UseVisualStyleBackColor = true;
            this.btnColorPicker.Click += new System.EventHandler(this.btnColorPicker_Click);
            // 
            // drawArea
            // 
            this.drawArea.BackColor = System.Drawing.Color.White;
            this.drawArea.Location = new System.Drawing.Point(0, 0);
            this.drawArea.Name = "drawArea";
            this.drawArea.Size = new System.Drawing.Size(884, 661);
            this.drawArea.TabIndex = 1;
            this.drawArea.TabStop = false;
            this.drawArea.Paint += new System.Windows.Forms.PaintEventHandler(this.drawArea_Paint);
            this.drawArea.MouseDown += new System.Windows.Forms.MouseEventHandler(this.drawArea_MouseDown);
            this.drawArea.MouseMove += new System.Windows.Forms.MouseEventHandler(this.drawArea_MouseMove);
            this.drawArea.MouseUp += new System.Windows.Forms.MouseEventHandler(this.drawArea_MouseUp);
            // 
            // colorsPanel1
            // 
            this.colorsPanel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(56)))), ((int)(((byte)(56)))));
            this.colorsPanel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.colorsPanel1.Dock = System.Windows.Forms.DockStyle.Right;
            this.colorsPanel1.Location = new System.Drawing.Point(834, 86);
            this.colorsPanel1.Name = "colorsPanel1";
            this.colorsPanel1.Size = new System.Drawing.Size(25, 575);
            this.colorsPanel1.TabIndex = 0;
            // 
            // colorsPanel2
            // 
            this.colorsPanel2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(56)))), ((int)(((byte)(56)))), ((int)(((byte)(56)))));
            this.colorsPanel2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.colorsPanel2.Dock = System.Windows.Forms.DockStyle.Right;
            this.colorsPanel2.Location = new System.Drawing.Point(859, 86);
            this.colorsPanel2.Name = "colorsPanel2";
            this.colorsPanel2.Size = new System.Drawing.Size(25, 575);
            this.colorsPanel2.TabIndex = 3;
            // 
            // frmPaint
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(884, 661);
            this.Controls.Add(this.colorsPanel1);
            this.Controls.Add(this.colorsPanel2);
            this.Controls.Add(this.toolbarPanel);
            this.Controls.Add(this.drawArea);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "frmPaint";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Paint";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.SizeChanged += new System.EventHandler(this.frmPaint_SizeChanged);
            this.toolbarPanel.ResumeLayout(false);
            this.basePanel.ResumeLayout(false);
            this.basePanel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.penSizeTBar)).EndInit();
            this.toolboxPanel.ResumeLayout(false);
            this.colorPickerPanel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.drawArea)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel toolbarPanel;
        private System.Windows.Forms.PictureBox drawArea;
        private System.Windows.Forms.Panel colorsPanel1;
        private System.Windows.Forms.Button btnEraser;
        private System.Windows.Forms.Button btnPencil;
        private System.Windows.Forms.Button btnEllipse;
        private System.Windows.Forms.Button btnRectangle;
        private System.Windows.Forms.Button btnLine;
        private System.Windows.Forms.Button btnColorPicker;
        private System.Windows.Forms.Panel currentColorPanel;
        private System.Windows.Forms.Panel toolboxPanel;
        private System.Windows.Forms.Panel colorPickerPanel;
        private System.Windows.Forms.Panel colorsPanel2;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Panel basePanel;
        private System.Windows.Forms.TrackBar penSizeTBar;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
    }
}

