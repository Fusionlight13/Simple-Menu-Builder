#ifndef MenuHelper_h
#define MenuHelper_h

#include <LiquidCrystal_I2C.h>
#include "../utilities/ArrayWrapper.h"

struct MenuItem
{
	const char *label;
	void (*action)();
};

template <size_t N>
class MenuHelper
{
private:
	LiquidCrystal_I2C &_lcd;
	ArrayWrapper<MenuItem, N> _items;
	size_t _selectedIndex = 0;

public:
	MenuHelper(
		LiquidCrystal_I2C &lcd,
		ArrayWrapper<MenuItem, N> &items)
		: _lcd(lcd), _items(items)
	{
	}

	bool addItem(const char *label, void (*action)())
	{
		MenuItem item{label, action};
		return _items.pushBack(item);
	}

	void select()
	{
		if (_items.count() == 0)
			return;

		MenuItem &item = _items[_selectedIndex];

		if (items.action != nullptr)
			items.action();
	}

	const char* currentLabel() const
	{
		if (_items.count() == 0) return "";

		return _items[_selectedIndex].label;
	}

	void next()
	{
		if (_items.count() == 0)
			return;

		_selectedIndex++;
		if (_selectedIndex >= _items.count())
			_selectedIndex = 0;
	}

	void previous()
	{
		if (_items.count() == 0)
			return;

		if (_selectedIndex == 0)
			_selectedIndex = _items.count() - 1;
		else
			_selectedIndex--;
	}

	void printCurrent()
	{
		_lcd.clear();
		_lcd.setCursor(0, 0);
		_lcd.print(currentLabel());
	}
};

#endif