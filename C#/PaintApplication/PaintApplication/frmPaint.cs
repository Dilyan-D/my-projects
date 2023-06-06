using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Windows.Forms;
using Newtonsoft.Json;

namespace PaintApplication
{
    public partial class frmPaint : Form
    {
        enum drawModes { Eraser, Pencil, Line, Rectangle, Ellipse }; // Draw modes
        drawModes drawMode = drawModes.Pencil; // Default draw mode
        Bitmap bitmap;
        Graphics g;
        Pen pen;
        bool isDrawing = false;     
        Point firstPoint = Point.Empty, secondPoint = Point.Empty;
        int ellipseW, ellipseH;
        Rectangle rect = Rectangle.Empty;

        public frmPaint()
        {
            InitializeComponent();

            // Resizing & repositioning draw area so that it works when the form is in fullscreen.
            int displayWidth = Screen.PrimaryScreen.Bounds.Width - (colorsPanel1.Width + colorsPanel2.Width);
            int displayHeight = Screen.PrimaryScreen.Bounds.Height - toolbarPanel.Height;
            drawArea.Size = new Size(displayWidth, displayHeight);
            drawArea.Location = new Point(0, toolbarPanel.Height);

            bitmap = new Bitmap(drawArea.Width, drawArea.Height);
            g = Graphics.FromImage(bitmap);
            g.Clear(Color.White);
            drawArea.Image = bitmap;
            pen = new Pen(currentColorPanel.BackColor, penSizeTBar.Value);
        }
        
        
        private void updateButtons()
        {
            Font defaultBtnFont = new Font("Verdana", 8, FontStyle.Regular);
            Color defaultBtnColor = Color.FromArgb(56, 56, 56);
            switch (drawMode)
            {
                case drawModes.Eraser:
                    {
                        // Button style when selected
                        btnEraser.Font = new Font(btnEraser.Font, FontStyle.Bold);
                        btnEraser.BackColor = Color.Black;

                        // Makes sure no other button is styled as selected
                        btnPencil.Font = defaultBtnFont;
                        btnPencil.BackColor = defaultBtnColor;
                        btnLine.Font = defaultBtnFont;
                        btnLine.BackColor = defaultBtnColor;
                        btnEllipse.Font = defaultBtnFont;
                        btnEllipse.BackColor = defaultBtnColor;
                        btnRectangle.Font = defaultBtnFont;
                        btnRectangle.BackColor = defaultBtnColor;
                        break;
                    }
                case drawModes.Pencil:
                    {
                        // Button style when selected
                        btnPencil.Font = new Font(btnPencil.Font, FontStyle.Bold);
                        btnPencil.BackColor = Color.Black;

                        // Makes sure no other button is styled as selected
                        btnEraser.Font = defaultBtnFont;
                        btnEraser.BackColor = defaultBtnColor;
                        btnLine.Font = defaultBtnFont;
                        btnLine.BackColor = defaultBtnColor;
                        btnEllipse.Font = defaultBtnFont;
                        btnEllipse.BackColor = defaultBtnColor;
                        btnRectangle.Font = defaultBtnFont;
                        btnRectangle.BackColor = defaultBtnColor;
                        break;
                    }
                case drawModes.Line:
                    {
                        // Button style when selected
                        btnLine.Font = new Font(btnLine.Font, FontStyle.Bold);
                        btnLine.BackColor = Color.Black;

                        // Makes sure no other button is styled as selected
                        btnEraser.Font = defaultBtnFont;
                        btnEraser.BackColor = defaultBtnColor;
                        btnPencil.Font = defaultBtnFont;
                        btnPencil.BackColor = defaultBtnColor;
                        btnEllipse.Font = defaultBtnFont;
                        btnEllipse.BackColor = defaultBtnColor;
                        btnRectangle.Font = defaultBtnFont;
                        btnRectangle.BackColor = defaultBtnColor;
                        break;
                    }
                case drawModes.Ellipse:
                    {
                        // Button style when selected
                        btnEllipse.Font = new Font(btnEllipse.Font, FontStyle.Bold);
                        btnEllipse.BackColor = Color.Black;

                        // Makes sure no other button is styled as selected
                        btnEraser.Font = defaultBtnFont;
                        btnEraser.BackColor = defaultBtnColor;
                        btnPencil.Font = defaultBtnFont;
                        btnPencil.BackColor = defaultBtnColor;
                        btnLine.Font = defaultBtnFont;
                        btnLine.BackColor = defaultBtnColor;
                        btnRectangle.Font = defaultBtnFont;
                        btnRectangle.BackColor = defaultBtnColor;
                        break;
                    }
                case drawModes.Rectangle:
                    {
                        // Button style when selected
                        btnRectangle.Font = new Font(btnRectangle.Font, FontStyle.Bold);
                        btnRectangle.BackColor = Color.Black;

                        // Makes sure no other button is styled as selected
                        btnEraser.Font = defaultBtnFont;
                        btnEraser.BackColor = defaultBtnColor;
                        btnPencil.Font = defaultBtnFont;
                        btnPencil.BackColor = defaultBtnColor;
                        btnLine.Font = defaultBtnFont;
                        btnLine.BackColor = defaultBtnColor;
                        btnEllipse.Font = defaultBtnFont;
                        btnEllipse.BackColor = defaultBtnColor;
                        break;
                    }

                default: { break; }
            }

        }

        private void createColorButtons()
        {
            colorsPanel1.Controls.Clear();
            colorsPanel2.Controls.Clear();
            int P1btnsCount = colorsPanel1.Height / 23;
            Button[] P1btnsArray = new Button[P1btnsCount];

            string json;
            using (StreamReader r = new StreamReader("../../colorButtons.json"))
            {
                json = r.ReadToEnd();
            }
            dynamic array = JsonConvert.DeserializeObject(json);
            short index = -1;

            for (int i = 0; i < P1btnsCount; i++)
                P1btnsArray[i] = new Button();

            foreach (Button btn in P1btnsArray)
            {
                Controls.Add(btn);
                btn.Parent = colorsPanel1;
                btn.Width = 23;
                btn.Height = 23;
                btn.Location = new Point(0, 0);
                btn.Anchor = (AnchorStyles.Top | AnchorStyles.Left);
                btn.Dock = DockStyle.Top;
                btn.FlatStyle = FlatStyle.Popup;
                btn.FlatAppearance.BorderColor = Color.DarkGray;
                btn.Text = "";
                btn.Name = array[++index].name;
                btn.BackColor = Color.FromName((string)array[index].color);
                btn.Click += new EventHandler(predefinedColor_Click);
            }


            Button[] P2btnsArray = new Button[P1btnsCount];

            for (int i = 0; i < P1btnsCount; i++)
                P2btnsArray[i] = new Button();

            foreach (Button btn in P2btnsArray)
            {
                Controls.Add(btn);
                btn.Parent = colorsPanel2;
                btn.Width = 23;
                btn.Height = 23;
                btn.Location = new Point(0, 0);
                btn.Anchor = (AnchorStyles.Top | AnchorStyles.Left);
                btn.Dock = DockStyle.Top;
                btn.FlatStyle = FlatStyle.Popup;
                btn.FlatAppearance.BorderColor = Color.DarkGray;
                btn.Text = "";
                btn.Name = array[index++].name;
                btn.BackColor = Color.FromName((string)array[index].color);
                btn.Click += new EventHandler(predefinedColor_Click);
            }
        }
       
        private void predefinedColor_Click(object sender, EventArgs e)
        {
            pen = new Pen(((Button)sender).BackColor, penSizeTBar.Value);
            currentColorPanel.BackColor = ((Button)sender).BackColor;
        }
        
        private void drawArea_MouseDown(object sender, MouseEventArgs e)
        {
            isDrawing = true;
            firstPoint = e.Location;
        }
        
        private void drawArea_MouseMove(object sender, MouseEventArgs e)
        {
            if (isDrawing)
            {
                switch (drawMode)
                {
                    case drawModes.Eraser:
                        {
                            Pen eraser = new Pen(Color.White, pen.Width);
                            Point p = new Point(e.X, e.Y);

                            eraser.StartCap = System.Drawing.Drawing2D.LineCap.Round;
                            eraser.EndCap = System.Drawing.Drawing2D.LineCap.Round;

                            if (!p.Equals(firstPoint))
                                secondPoint = p;

                            g.DrawLine(eraser, secondPoint, firstPoint);
                            firstPoint = secondPoint;

                            break;
                        }
                    case drawModes.Pencil:
                        {
                            Point p = new Point(e.X, e.Y);
                            pen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
                            pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;
                            if (!p.Equals(firstPoint))
                                secondPoint = p;

                            g.DrawLine(pen, secondPoint, firstPoint);
                            firstPoint = secondPoint;

                            break;
                        }
                    case drawModes.Line:
                        {
                            Point p = new Point(e.X, e.Y);

                            if (!p.Equals(firstPoint))
                            {
                                secondPoint = p;
                            }
                            break;
                        }
                    case drawModes.Ellipse:
                        {
                            Point p = new Point(e.X, e.Y);

                            if (!p.Equals(firstPoint))
                                secondPoint = p;

                            ellipseW = secondPoint.X - firstPoint.X;
                            ellipseH = secondPoint.Y - firstPoint.Y;

                            break;
                        }
                    case drawModes.Rectangle:
                        {
                            Point p = new Point(e.X, e.Y);

                            if (!p.Equals(firstPoint))
                                secondPoint = p;

                            if (!firstPoint.Equals(secondPoint) && !secondPoint.Equals(Point.Empty))
                            {
                                if (firstPoint.X < secondPoint.X)
                                {
                                    rect.X = firstPoint.X;
                                    rect.Width = secondPoint.X - firstPoint.X;
                                }
                                else
                                {
                                    rect.X = secondPoint.X;
                                    rect.Width = firstPoint.X - secondPoint.X;
                                }
                                if (firstPoint.Y < secondPoint.Y)
                                {
                                    rect.Y = firstPoint.Y;
                                    rect.Height = secondPoint.Y - firstPoint.Y;
                                }
                                else
                                {
                                    rect.Y = secondPoint.Y;
                                    rect.Height = firstPoint.Y - secondPoint.Y;
                                }
                            }
                            break;
                        }

                    default: { break; }
                }
            }
            drawArea.Refresh();

        }

        private void drawArea_MouseUp(object sender, MouseEventArgs e)
        {
            isDrawing = false;

            switch (drawMode)
            {
                case drawModes.Ellipse:
                    {
                        if (!firstPoint.Equals(secondPoint) && !secondPoint.Equals(Point.Empty))
                        {
                            g.DrawEllipse(pen, firstPoint.X, firstPoint.Y, ellipseW, ellipseH);
                            secondPoint = Point.Empty; // Setting to empty to avoid drawing shape on mouse click only (user needs to drag the mouse)
                        }

                        break;
                    }
                case drawModes.Rectangle:
                    {
                        if (!firstPoint.Equals(secondPoint) && !secondPoint.Equals(Point.Empty))
                        {
                            g.DrawRectangle(pen, rect);
                            secondPoint = Point.Empty; // Setting to empty to avoid drawing shape on mouse click only (user needs to drag the mouse)
                        }

                        break;
                    }
                case drawModes.Line:
                    {
                        if (!firstPoint.Equals(secondPoint) && !secondPoint.Equals(Point.Empty))
                        {
                            g.DrawLine(pen, firstPoint.X, firstPoint.Y, secondPoint.X, secondPoint.Y);
                            secondPoint = Point.Empty; // Setting to empty to avoid drawing shape on mouse click only (user needs to drag the mouse)
                        }

                        break;
                    }

                default: { break; }
            }

        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            g.Clear(Color.White);
            drawArea.Image = bitmap;
            pen.Color = Color.Black;
            pen.Width = 3;
            currentColorPanel.BackColor = Color.Black;
            penSizeTBar.Value = 3;
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            SaveFileDialog sfd = new SaveFileDialog();
            sfd.Filter = "JPEG (*.jpg;*.jpeg;*.jpe;*.jfif)|*.jpg;*.jpeg;*.jpe;*.jfif";

            if (sfd.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    bitmap.Save(sfd.FileName, ImageFormat.Jpeg);
                }
                catch
                {
                    MessageBox.Show("Error", "There's been an error trying to save this drawing!",
                        MessageBoxButtons.OK, MessageBoxIcon.Error);
                }

            }
        }
        private void penSizeTBar_Scroll(object sender, EventArgs e)
        {
            pen.Width = penSizeTBar.Value;
        }

        private void btnEraser_Click(object sender, EventArgs e)
        {
            drawMode = drawModes.Eraser;
            updateButtons();
        }

        private void btnPencil_Click(object sender, EventArgs e)
        {
            drawMode = drawModes.Pencil;
            updateButtons();
        }
        
        private void btnLine_Click(object sender, EventArgs e)
        {
            drawMode = drawModes.Line;
            pen.StartCap = System.Drawing.Drawing2D.LineCap.Flat;
            pen.EndCap = System.Drawing.Drawing2D.LineCap.Flat;
            updateButtons();
        }

        private void btnEllipse_Click(object sender, EventArgs e)
        {
            drawMode = drawModes.Ellipse;
            updateButtons();
        }

        private void btnRectangle_Click(object sender, EventArgs e)
        {
            drawMode = drawModes.Rectangle;
            updateButtons();
        }

        private void btnColorPicker_Click(object sender, EventArgs e)
        {
            ColorDialog colDlg = new ColorDialog();
            colDlg.ShowDialog();
            currentColorPanel.BackColor = colDlg.Color;
            pen.Color = colDlg.Color;
        }

        private void drawArea_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            if (isDrawing)
            {
                switch (drawMode)
                {
                    case drawModes.Ellipse:
                        {
                            g.DrawEllipse(pen, firstPoint.X, firstPoint.Y, ellipseW, ellipseH);
                            break;
                        }
                    case drawModes.Rectangle:
                        {
                            g.DrawRectangle(pen, rect);
                            break;
                        }
                    case drawModes.Line:
                        {
                            g.DrawLine(pen, firstPoint.X, firstPoint.Y, secondPoint.X, secondPoint.Y);
                            break;
                        }

                    default: { break; }
                }
            }
        }
        
        private void frmPaint_SizeChanged(object sender, EventArgs e)
        {
            toolboxPanel.Left = (toolboxPanel.Parent.Width - toolboxPanel.Width) / 2 - 18;
            toolboxPanel.Top = (toolboxPanel.Parent.Height - toolboxPanel.Height) / 2;

            colorPickerPanel.Left = (colorPickerPanel.Parent.Width - colorPickerPanel.Width) - 10;
            colorPickerPanel.Top = (colorPickerPanel.Parent.Height - colorPickerPanel.Height) / 2;

            basePanel.Left = 10;
            basePanel.Top = (basePanel.Parent.Height - basePanel.Height) / 2;
            createColorButtons();
        }
    }

}