#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ img1 = gcnew Bitmap("1.png");
		Bitmap^ img2 = gcnew Bitmap("2.png");
		Bitmap^ img3 = gcnew Bitmap("3.png");
		Bitmap^ img4 = gcnew Bitmap("4.png");
		int x = 0;
	private: System::Windows::Forms::Timer^ timer1;
		   
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->DoubleBuffered = true;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
				delete img1;
				delete img2;
				delete img3;
				delete img4;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1004, 543);
			this->Name = L"MyForm";
			this->Text = L"waza";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		timer1->Start();
	}
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			   Graphics^ g = e->Graphics;
			   int w = this->ClientRectangle.Width;
			   int h = this->ClientRectangle.Height;
			   g->DrawImage(img1,	x,0,w,h);
			   g->DrawImage(img2, x, 0, w,h);
			   g->DrawImage(img3, x, 0, w,h);
			   g->DrawImage(img4, x, 0, w,h);

			   g->DrawImage(img1, x-w, 0, w, h);
			   g->DrawImage(img2, x-w, 0, w, h);
			   g->DrawImage(img3, x-w, 0, w, h);
			   g->DrawImage(img4, x-w, 0, w, h);
		   }
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		x +=10;
		if (x>this->ClientRectangle.Width)
		{
			x + 0;
		}
		this->Invalidate();
	}
	};
}
