#include <QWidget>
#include <QGridLayout>
#include <QLabel>

#include <QChartView>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>

// TODO: Use QtCreator to generate .ui file instead of making the ui in code.
class HomeScreen : public QWidget
{
	Q_OBJECT

public:
	HomeScreen(QWidget* parent = nullptr);

private:
	void createTestPlot(QChartView* parent);

private:
	QWidget* parent;
	QGridLayout* layout;

	QLabel* label11;
	QLabel* label21;
	
	QChartView* plot;
};