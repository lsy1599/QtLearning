#ifndef QUADSPLITTER_H
#define QUADSPLITTER_H

#include <QFrame>

class QuadSplitterPrivate;

class QuadSplitter : public QFrame
{
	Q_OBJECT
public:
	QuadSplitter(QWidget *parent);
	~QuadSplitter();

	void addWidget(QWidget *, int row, int column);

	int spacing() const;
	void setSpacing(int spacing);

	int splittersSpacing() const;
	void setSplittersSpacing(int spacing);

	int centerPartWidth() const;
	void setCenterPartWidth(int value);

	int minimumWidgetSize() const;
	void setMinimumWidgetSize(int value);
protected:
	void resizeEvent(QResizeEvent *);
private:
	QuadSplitterPrivate * const d_ptr;
	Q_DISABLE_COPY(QuadSplitter)
	Q_DECLARE_PRIVATE(QuadSplitter);
	friend class AdvSplitter;
};

#endif // QUADSPLITTER_H
