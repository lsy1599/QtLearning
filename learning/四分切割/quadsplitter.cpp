#include "quadsplitter.h"
#include <QScopedPointer>
#include <QPointer>
#include <QStylePainter>
#include <QStyleOption>
#include <QMouseEvent>
#include <QtCore/qmath.h>

class AdvSplitter;

class QuadSplitterPrivate : public QObject
{
	Q_DECLARE_PUBLIC(QuadSplitter);
public: 
	QuadSplitterPrivate(QuadSplitter* _q_ptr);
	void addWidget(QWidget *widget, int row, int column);
	void splitterMoveStart(AdvSplitter* splitter, bool center);
	void splitterMove(AdvSplitter* splitter, QPoint const& offset, bool center);
	void arrange();
	qreal realPercent(Qt::Orientation orientation) const;

	int spacing() const;
	void setSpacing(int spacing);

	int splittersSpacing() const;
	void setSplittersSpacing(int spacing);

	int centerPartWidth() const;
	void setCenterPartWidth(int value);

	int minimumWidgetSize() const;
	void setMinimumWidgetSize(int value);
private:
	QuadSplitter *q_ptr;

	QScopedPointer<AdvSplitter> _horizontalSplitter;
	QScopedPointer<AdvSplitter> _verticalSplitter;

	QPointer<QWidget> _grid[2][2];
	int _spacing;
	int _splittersSpacing;
	QPoint _splittersMovingPos;
	int _minimumWidgetSize;
	int _centerPart;

	int realSpacing() const;
	int realWidth() const;
	int realHeight() const;
};
//////////////////////////////////////////////////////////////////////////
class AdvSplitter : public QWidget
{
public:
	AdvSplitter(QWidget* parent, QuadSplitterPrivate* priv, Qt::Orientation orientation)
		: QWidget(parent), _percent(0.5), _orientation(orientation), 
		_mouse(false), _center(false), _private(priv)
	{
		setMouseTracking(true);
		if (orientation == Qt::Horizontal)
			setCursor(Qt::SplitHCursor);
		else if (orientation == Qt::Vertical)
			setCursor(Qt::SplitVCursor);
	}
	
	qreal percent() const
	{
		return _percent;
	}

	void setPercent(qreal val)  
	{
		_percent = val;
	}
protected:
	void paintEvent (QPaintEvent *event)
	{
		QStylePainter painter(this);
		QStyleOption opt1, opt2;
		opt1.init(this);
		opt2.init(this);
		opt1.state = opt2.state = QStyle::State_None;
		if (_orientation == Qt::Horizontal)
		{
			opt1.state |= QStyle::State_Horizontal;
			opt2.state |= QStyle::State_Horizontal;

			if (_private)
			{
				int hiPart = qFloor((qreal)opt1.rect.height() * _private->realPercent(Qt::Vertical) + 0.5);
				int loPart = opt1.rect.height() - hiPart;
				opt1.rect.setBottom(opt1.rect.top() + hiPart);
				opt2.rect.setTop(opt2.rect.bottom() - loPart);
			}
		}
		else if (_private)
		{
			int hiPart = qFloor((qreal)opt1.rect.width() * _private->realPercent(Qt::Horizontal) + 0.5);
			int loPart = opt1.rect.width() - hiPart;
			opt1.rect.setRight(opt1.rect.left() + hiPart);
			opt2.rect.setLeft(opt2.rect.right() - loPart);
		}

		painter.drawControl(QStyle::CE_Splitter, opt1);
		if (_private)
			painter.drawControl(QStyle::CE_Splitter, opt2);
	}
	
	void mouseMoveEvent(QMouseEvent * event)
	{
		if (!_mouse && _private)
		{
			if (_orientation == Qt::Horizontal)
			{
				int hiPart = qFloor((qreal)height() * _private->realPercent(Qt::Vertical) + 0.5);
				if (event->pos().y() > (hiPart - _private->centerPartWidth() / 2) && 
					event->pos().y() < (hiPart + _private->centerPartWidth() / 2))
					setCursor(Qt::SizeAllCursor);
				else
					setCursor(Qt::SplitHCursor);
			}
			else
			{
				int hiPart = qFloor((qreal)width() * _private->realPercent(Qt::Horizontal) + 0.5);
				if (event->pos().x() > (hiPart - _private->centerPartWidth() / 2) && 
					event->pos().x() < (hiPart + _private->centerPartWidth() / 2))
					setCursor(Qt::SizeAllCursor);
				else
					setCursor(Qt::SplitVCursor);
			}
		}
		else if (_center)
		{
			if (cursor().shape() != Qt::SizeAllCursor) 
				setCursor(Qt::SizeAllCursor);
		}
		else if (_orientation == Qt::Horizontal)
		{
			if (cursor().shape() != Qt::SplitHCursor)
				setCursor(Qt::SplitHCursor);
		}
		else if (cursor().shape() != Qt::SplitVCursor)
			setCursor(Qt::SplitVCursor);

		if (_mouse && (event->buttons() & Qt::LeftButton))
		{
			QPoint pt = mapToParent(event->pos());

			if (QuadSplitter* p = qobject_cast<QuadSplitter*>(parent()))
				p->d_ptr->splitterMove(this, pt - _mousePos, _center);
		}
	}
	
	void mousePressEvent(QMouseEvent *event)
	{
		if (event->button() == Qt::LeftButton)
		{
			_mouse = true;
			if (_private)
			{
				if (_orientation == Qt::Horizontal)
				{
					int hiPart = qFloor((qreal)height() * _private->realPercent(Qt::Vertical) + 0.5);
					if (event->pos().y() > (hiPart - _private->centerPartWidth() / 2) && 
						event->pos().y() < (hiPart + _private->centerPartWidth() / 2))
					{
						_center = true;
						setCursor(Qt::SizeAllCursor);
					}
					else
						setCursor(Qt::SplitHCursor);
				}
				else
				{
					int hiPart = qFloor((qreal)width() * _private->realPercent(Qt::Horizontal) + 0.5);
					if (event->pos().x() > (hiPart - _private->centerPartWidth() / 2) && 
						event->pos().x() < (hiPart + _private->centerPartWidth() / 2))
					{
						_center = true;
						setCursor(Qt::SizeAllCursor);
					}
					else
						setCursor(Qt::SplitVCursor);
				}
			}
		}
		_mousePos = mapToParent(event->pos());
		if (QuadSplitter* p = qobject_cast<QuadSplitter*>(parent()))
			p->d_ptr->splitterMoveStart(this, _center);
	}
	
	void mouseReleaseEvent(QMouseEvent *event)
	{
		_mouse = false;
		_center = false;
	}
private:
	bool _mouse;
	QPoint _mousePos;
	Qt::Orientation _orientation;
	qreal _percent;
	QPointer<QuadSplitterPrivate> _private;
	bool _center;
};
//////////////////////////////////////////////////////////////////////////
QuadSplitterPrivate::QuadSplitterPrivate(QuadSplitter* _q_ptr) 
	: q_ptr(_q_ptr), _spacing(5), _splittersSpacing(5), 
	_minimumWidgetSize(30), _centerPart(30)
{
	Q_Q(QuadSplitter);
	_horizontalSplitter.reset(new AdvSplitter(q, this, Qt::Horizontal));
	_verticalSplitter.reset(new AdvSplitter(q, this, Qt::Vertical));

	arrange();
}

int QuadSplitterPrivate::realSpacing() const
{
	const Q_Q(QuadSplitter);
	return _spacing + q->frameWidth();
}

int QuadSplitterPrivate::realWidth() const
{
	const Q_Q(QuadSplitter);
	return q->width() - (realSpacing() * 2) - _splittersSpacing;
}

int QuadSplitterPrivate::realHeight() const
{
	const Q_Q(QuadSplitter);
	return q->height() - (realSpacing() * 2) - _splittersSpacing;
}

void QuadSplitterPrivate::arrange()
{
	Q_Q(QuadSplitter);

	QPair<int, int> minMaxHorizontalSizes[2] = 
		{QPair<int, int>(0, QWIDGETSIZE_MAX), QPair<int, int>(0, QWIDGETSIZE_MAX)};

	QPair<int, int> minMaxVerticalSizes[2] = 
		{QPair<int, int>(0, QWIDGETSIZE_MAX), QPair<int, int>(0, QWIDGETSIZE_MAX)};
		
	for (int r = 0; r < 2; ++r)
	{
		for (int c = 0; c < 2; ++c)
		{
			if (_grid[r][c] && _grid[r][c]->parent() == q)
			{
				minMaxHorizontalSizes[c] = 
					QPair<int, int>(
					qMax(_grid[r][c]->minimumWidth() < _minimumWidgetSize ? _minimumWidgetSize : _grid[r][c]->minimumWidth(),
						minMaxHorizontalSizes[c].first),
					qMin(_grid[r][c]->maximumWidth(), minMaxHorizontalSizes[c].second));

				minMaxVerticalSizes[r] = 
					QPair<int, int>(
					qMax(_grid[r][c]->minimumHeight() < _minimumWidgetSize ? _minimumWidgetSize : _grid[r][c]->minimumHeight(),
						minMaxVerticalSizes[r].first),
					qMin(_grid[r][c]->maximumHeight(), minMaxVerticalSizes[r].second));
			}
			else
				_grid[r][c] = nullptr;
		}
	}

	//columns
	int leftColumnWidth = qFloor((qreal)realWidth() * _horizontalSplitter->percent() + 0.5);
	if (leftColumnWidth < minMaxHorizontalSizes[0].first)
		leftColumnWidth = minMaxHorizontalSizes[0].first;
	if (leftColumnWidth > minMaxHorizontalSizes[0].second)
		leftColumnWidth = minMaxHorizontalSizes[0].second;

	int columnWidth = leftColumnWidth;

	int rightColumnWidth = realWidth() - leftColumnWidth;
	if (rightColumnWidth < minMaxHorizontalSizes[1].first)
	{
		rightColumnWidth = minMaxHorizontalSizes[1].first;
		columnWidth = realWidth() - rightColumnWidth;
	}
	if (rightColumnWidth > minMaxHorizontalSizes[1].second)
	{
		rightColumnWidth = minMaxHorizontalSizes[1].second;
		columnWidth = realWidth() - rightColumnWidth;
	}
	//rows
	int topColumnHeight = qFloor((qreal)realHeight() * _verticalSplitter->percent() + 0.5);
	if (topColumnHeight < minMaxVerticalSizes[0].first)
		topColumnHeight = minMaxVerticalSizes[0].first;
	if (topColumnHeight > minMaxVerticalSizes[0].second)
		topColumnHeight = minMaxVerticalSizes[0].second;

	int columnHeight = topColumnHeight;

	int bottomColumnHeight = realHeight() - topColumnHeight;
	if (bottomColumnHeight < minMaxVerticalSizes[1].first)
	{
		bottomColumnHeight = minMaxVerticalSizes[1].first;
		columnHeight = realHeight() - bottomColumnHeight;
	}
	if (bottomColumnHeight > minMaxVerticalSizes[1].second)
	{
		bottomColumnHeight = minMaxVerticalSizes[1].second;
		columnHeight = realHeight() - bottomColumnHeight;
	}

	_horizontalSplitter->setGeometry(realSpacing() + columnWidth, realSpacing(), _splittersSpacing, q->height() - realSpacing() * 2);
	_horizontalSplitter->raise();

	_verticalSplitter->setGeometry(realSpacing(), realSpacing() + columnHeight, q->width() - realSpacing() * 2, _splittersSpacing);
	_verticalSplitter->raise();

	if (_grid[0][0])
		_grid[0][0]->setGeometry(realSpacing(), realSpacing(), columnWidth, columnHeight);
	if (_grid[0][1])
		_grid[0][1]->setGeometry(realSpacing() + columnWidth + _splittersSpacing, realSpacing(), realWidth() - columnWidth, columnHeight);

	if (_grid[1][0])
		_grid[1][0]->setGeometry(realSpacing(), 
			realSpacing() + columnHeight + _splittersSpacing, columnWidth, realHeight() - columnHeight);
	if (_grid[1][1])
		_grid[1][1]->setGeometry(realSpacing() + columnWidth + _splittersSpacing, 
			realSpacing() + columnHeight + _splittersSpacing, realWidth() - columnWidth, realHeight() - columnHeight);
}

void QuadSplitterPrivate::addWidget(QWidget *widget, int row, int column)
{
	Q_Q(QuadSplitter);
	if (row < 0 || column < 0 || row > 1 || column > 1) {
		qWarning("QGridLayout: Cannot add %s/%s to %s/%s at row %d column %d",
			widget->metaObject()->className(), widget->objectName().toLocal8Bit().data(),
			q->metaObject()->className(), q->objectName().toLocal8Bit().data(), row, column);
		return;
	}

	bool needShow = q->isVisible() &&
		!(widget->isHidden() && widget->testAttribute(Qt::WA_WState_ExplicitShowHide));
	if (widget->parentWidget() != q)
		widget->setParent(q);
	if (needShow)
		widget->show();

	_grid[row][column] = widget;
		
	arrange();
}

void QuadSplitterPrivate::splitterMoveStart(AdvSplitter* splitter, bool center)
{
	_splittersMovingPos = QPoint(_horizontalSplitter->x(), _verticalSplitter->y());
}

void QuadSplitterPrivate::splitterMove(AdvSplitter* splitter, QPoint const& offset, bool center)
{
	Q_Q(QuadSplitter);
	if (center)
	{
		qreal newX = _splittersMovingPos.x() + offset.x() - realSpacing();
		qreal newY = _splittersMovingPos.y() + offset.y() - realSpacing();
		_horizontalSplitter->setPercent(newX / (qreal)realWidth());
		_verticalSplitter->setPercent(newY / (qreal)realHeight());
	}
	else if (splitter == _horizontalSplitter.data())
	{
		qreal newX = _splittersMovingPos.x() + offset.x() - realSpacing();
		splitter->setPercent(newX / (qreal)realWidth());
	}
	else
	{
		qreal newY = _splittersMovingPos.y() + offset.y() - realSpacing();
		splitter->setPercent(newY / (qreal)realHeight());
	}
	arrange();
}

int QuadSplitterPrivate::splittersSpacing() const
{
	return _splittersSpacing;
}

void QuadSplitterPrivate::setSplittersSpacing(int spacing)
{
	_splittersSpacing = spacing;
}

qreal QuadSplitterPrivate::realPercent(Qt::Orientation orientation) const
{
	if (orientation == Qt::Horizontal)
	{
		qreal newX = _horizontalSplitter->x() - realSpacing();
		return newX / realWidth();
	}
	
	qreal newY = _verticalSplitter->y() - realSpacing();
	return newY / realHeight();
}

int QuadSplitterPrivate::spacing() const
{
	return _spacing;
}

void QuadSplitterPrivate::setSpacing(int spacing)
{
	_spacing = spacing;
}

int QuadSplitterPrivate::centerPartWidth() const
{
	return _centerPart;
}

void QuadSplitterPrivate::setCenterPartWidth(int value)
{
	_centerPart = value;
}

int QuadSplitterPrivate::minimumWidgetSize() const
{
	return _minimumWidgetSize;
}

void QuadSplitterPrivate::setMinimumWidgetSize(int value)
{
	_minimumWidgetSize = value;
}

//////////////////////////////////////////////////////////////////////////
QuadSplitter::QuadSplitter(QWidget *parent)
	: QFrame(parent), d_ptr(new QuadSplitterPrivate(this))
{
}

QuadSplitter::~QuadSplitter()
{
	delete d_ptr;
}

void QuadSplitter::addWidget(QWidget *widget, int row, int column)
{
	Q_D(QuadSplitter);
	d->addWidget(widget, row, column);
}

void QuadSplitter::resizeEvent(QResizeEvent *event)
{
	Q_D(QuadSplitter);
	d->arrange();
}

int QuadSplitter::spacing() const
{
	const Q_D(QuadSplitter);
	return d->spacing();
}

void QuadSplitter::setSpacing(int spacing)
{
	Q_D(QuadSplitter);
	d->setSpacing(spacing);
}

int QuadSplitter::splittersSpacing() const
{
	const Q_D(QuadSplitter);
	return d->splittersSpacing();
}

void QuadSplitter::setSplittersSpacing(int spacing)
{
	Q_D(QuadSplitter);
	d->setSplittersSpacing(spacing);
}

int QuadSplitter::centerPartWidth() const
{
	const Q_D(QuadSplitter);
	return d->centerPartWidth();
}

void QuadSplitter::setCenterPartWidth(int value)
{
	Q_D(QuadSplitter);
	d->setCenterPartWidth(value);
}

int QuadSplitter::minimumWidgetSize() const
{
	const Q_D(QuadSplitter);
	return d->minimumWidgetSize();
}

void QuadSplitter::setMinimumWidgetSize(int value)
{
	Q_D(QuadSplitter);
	d->setMinimumWidgetSize(value);
}
