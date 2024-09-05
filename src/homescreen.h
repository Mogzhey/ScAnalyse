#include <QWidget>
#include <QGridLayout>
#include <QLabel>

// TODO: Use QtCreator to generate .ui file instead of making the ui in code.
class HomeScreen : public QWidget
{
	Q_OBJECT

public:
	HomeScreen(QWidget* parent = nullptr);

private:
	QWidget* parent;
	QGridLayout* layout;

	QLabel* label11;
	QLabel* label12;
	QLabel* label21;
	QLabel* label22;
};