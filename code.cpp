# include <Siv3D.hpp> // OpenSiv3D v0.6.10

void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// 画像ファイルからテクスチャを作成する | Create a texture from an image file
	const Texture texture{ U"example/windmill.png" };

	// 絵文字からテクスチャを作成する | Create a texture from an emoji
	const Texture emoji{ U"🦖"_emoji };

	// 太文字のフォントを作成する | Create a bold font with MSDF method
	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	// テキストに含まれる絵文字のためのフォントを作成し、font に追加する | Create a font for emojis in text and add it to font as a fallback
	const Font emojiFont{ 48, Typeface::ColorEmoji };
	font.addFallback(emojiFont);

	Array <int32> husen(100,0);
	double x = 50;
	int32 pas = -1;
	int32 ans = 75;
	double cool = 1.0;
	double cool2 = 1.0;
	Scene::SetBackground(Palette::White);
	Stopwatch stopwatch;
	bool ok = false;
	bool ok2 = false;
	while (System::Update())
	{
		// 角丸長方形を描く | Draw a rounded rectangle
		RoundRect{ 100, 300, 600, 200, 20 }.draw(ColorF{ 1.0,1.0,0.6 });
		cool += Scene::DeltaTime();
		cool2 += Scene::DeltaTime();
		if (cool >= 100.0) {
			cool = 2.0;
		}
		if (cool2 >= 100.0) {
			cool2 = 2.0;
		}
		if (ok&&pas!=-1) {
			const double p2 = Periodic::Sine0_1(2s);
			RoundRect{ 100, 500, p2 * 600, 100, 20 }.draw(ColorF{ 1.0,1-p2,0.0 });
			if (stopwatch.sF()>=2.00) {
				ok = false;
				ok2 = true;
				stopwatch.pause();
			}
		}
		else if (ok&&pas==-1) {
			ok = false;
		}
		else if ((KeyO.pressed() == true && cool >= 1.0)) {
			cool = 0.0;
			ok = true;
			stopwatch.restart();
		}
		else if(ok2){
			RoundRect{ 100, 500, ans * 6, 100, 20 }.draw(ColorF{ 1.0,((double)ans) / 100,0.0 });
			/*			for (long double i = x; i <= 100; i += 0.01) {
				x=i;
				RoundRect{ 100, 500, x*6, 100, 20 }.draw(ColorF{ 1.0,((double)x) / 100,0.0 });

			}
			for (long double i = 100; i >= ans; i -= 0.01) {
				x=i;
					RoundRect{ 100, 500, x*6, 100, 20 }.draw(ColorF{ 1.0,((double)x) / 100,0.0 });
			}*/
			int32 destoryed_husen = 0;
			for (auto i : step(100)) {
				if (husen[i] == 0) {
					destoryed_husen++;
					husen[i] = 1;
				}
				if (destoryed_husen == abs(ans - pas)) {
					break;
				}
			}
			ok2 = false;
			x = ans;
			pas = -1;
	    }
		else {
			RoundRect{ 100, 500, x * 6, 100, 20 }.draw(ColorF{ 1.0,((double)x) / 100,0.0 });
		}
		int nowhusen = 0;
		for (auto i : step(100)) {
			if (husen[i] == 0) {
				int32 y = i % 10;
				int32 z = i / 10;
				Circle{ 100+y*60, 100+z*20, 30 }.draw(ColorF{1.0,0.0,0.0});
				nowhusen++;
			}
		}
		if (nowhusen == 0) {
			font(U"GAME OVER")
				.draw(100, Rect{ 20, 20, 800, 800 }, Palette::Red);

		}
		if (Key0.pressed()&&cool2>=0.3) {
			if (pas != -1) {
				pas *= 10;
				pas += 0;
			}
			else {
				pas = 0;
			}
			cool2 = 0.0;
		}
		if (Key1.pressed() && cool2 >= 0.3) {
			if (pas!= -1) {
				pas *= 10;
				pas += 1;
			}
			else {
				pas = 1;
			}
			cool2 = 0.0;
		}
		if (Key2.pressed() && cool2 >= 0.3) {
			if (pas != -1) {
				pas *= 10;
				pas += 2;
			}
			else {
				pas = 2;
			}
			cool2 = 0.0;
		}
		if (Key3.pressed() && cool2 >= 0.3) {
			if (pas != -1) {
				pas *= 10;
				pas += 3;
			}
			else {
				pas = 3;
			}
			cool2 = 0.0;
		}
		if (Key4.pressed() && cool2 >= 0.3) {
			if (pas != -1) {
				pas *= 10;
				pas += 4;
			}
			else {
				pas = 4;
			}
			cool2 = 0.0;
		}
		if (Key5.pressed() && cool2 >= 0.3) {
			if (pas != -1) {
				pas *= 10;
				pas += 5;
			}
			else {
				pas = 5;
			}
			cool2 = 0.0;
		}
		if (Key6.pressed() && cool2 >= 0.3) {
			if (pas != -1) {
				pas *= 10;
				pas += 6;
			}
			else {
				pas = 6;
			}
			cool2 = 0.0;
		}
		if (Key7.pressed() && cool2 >= 0.3) {
			if (pas != -1) {
				pas *= 10;
				pas += 7;
			}
			else {
				pas = 7;
			}
			cool2 = 0.0;
		}
		if (Key8.pressed() && cool2 >= 0.3) {
			if (pas != -1) {
				pas *= 10;
				pas += 8;
			}
			else {
				pas = 8;
			}
			cool2 = 0.0;
		}
		if (Key9.pressed() && cool2 >= 0.3) {
			if (pas != -1) {
				pas *= 10;
				pas += 9;
			}
			else {
				pas = 9;
			}
			cool2 = 0.0;
		}
		if (KeyBackspace.pressed() && cool2 >= 0.3) {
			cool2 = 0.0;
			if (pas >= 10) {
				pas /= 10;
			}
			else {
				pas = -1;
			}
		}
		if (pas == -1)font(U"--").draw(32, Rect{700, 500, 100, 100}, Palette::Black);
		else font(pas).draw(32, Rect{ 700, 500, 100, 100 }, Palette::Black);
	}
}
