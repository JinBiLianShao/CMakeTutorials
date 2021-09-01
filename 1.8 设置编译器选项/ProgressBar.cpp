#include "ProgressBar.h"

ProgressBar::ProgressBar()
    // 25 spaces
    : m_bar("[                                                  ]")
    , m_shap("#")
{
}

void ProgressBar::run()
{
    int i = 0;
    std::string::size_type pos = 0;

    while (true)
    {
        // 休眠 0 ~ 200 毫秒。
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
        // 因为进度条的 '#' 只有 50 个，所以每一个 '#' 代表 2%。
        if (pos++ % 2)
        {
            // 将 ' ' 替换为 '#'。
            this->m_bar.replace(pos / 2, 1, "#");
        }

        // 输出进度条。
        std::cout << '\r' << this->m_bar << " " << i << " %" << std::flush;

        if (i++ == 100)
        {
            std::cout << "\ndone.\n";
            break;
        }
    }
}
