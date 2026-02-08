#include "key.h"
#include "cmsis_os2.h"
#include "PageManager.h"
#include "ui_HomePage.h"
#include "ui_MenuPage.h"

void Key_task(void *argument)
{
    int k;
	Key_GPIO_Init();
	while (1) {
        k = KeyScan();
		if (k && (Page_Get_NowPage()->page_obj == &ui_HomePage)) {
			Page_Load(&Page_Menu);
		}
		osDelay(10);
	}
}
