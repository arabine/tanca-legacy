#include "SelectionWindow.h"
#include "TableHelper.h"
#include "Log.h"

SelectionWindow::SelectionWindow(QWidget *parent, const QString &title, int minSize, int maxSize)
    : QDialog(parent)
    , mHelper(NULL)
    , mMinSize(minSize)
    , mMaxSize(maxSize)
{
    ui.setupUi(this);
    ui.labelTitle->setText(title);
    ui.spinSelectionNumber->setMinimum(0);

    mHelper.SetTableWidget(ui.playersTable);

    connect(ui.buttonOk, SIGNAL(clicked(bool)), this, SLOT(slotAccept()));
    connect(ui.buttonCancel, SIGNAL(clicked(bool)), this, SLOT(reject()));
    connect(ui.buttonSwap, &QPushButton::clicked, this, &SelectionWindow::slotClicked);

    connect(ui.playersTable, SIGNAL(itemSelectionChanged()), this, SLOT(slotPlayerItemActivated()));
    connect(ui.selectionList, &QListWidget::itemClicked, this, &SelectionWindow::slotSelectionItemActivated);
}

void SelectionWindow::SetHeader(const QStringList &tableHeader)
{
    mTableHeader = tableHeader;
}

void SelectionWindow::StartUpdate(int size)
{
    ui.playersTable->clear();
    ui.selectionList->clear();

    mHelper.Initialize(mTableHeader, size);
}

void SelectionWindow::FinishUpdate()
{
    mHelper.Finish();
}

void SelectionWindow::AddLeftEntry(const QList<QVariant> &rowData)
{
    mHelper.AppendLine(rowData, false);
}

void SelectionWindow::AddRightEntry(const QString &text)
{
    ui.selectionList->addItem(text);
}

void SelectionWindow::SetNumber(std::uint32_t number)
{
    ui.spinSelectionNumber->setValue(number);
}

uint32_t SelectionWindow::GetNumber()
{
    return ui.spinSelectionNumber->value();
}

void SelectionWindow::AllowZeroNumber(bool enable)
{
    if (enable)
    {
        ui.spinSelectionNumber->setMinimum(0);
    }
    else
    {
        ui.spinSelectionNumber->setMinimum(1);
    }
}

void SelectionWindow::slotPlayerItemActivated()
{
    ui.selectionList->clearSelection();
    ui.selectionList->clearFocus();
}

void SelectionWindow::slotSelectionItemActivated(QListWidgetItem *item)
{
    (void) item;
    ui.playersTable->clearSelection();
    ui.playersTable->clearFocus();
}

void SelectionWindow::slotClicked()
{
    int selectionRight = ui.selectionList->currentRow();
    TableHelper helper(ui.playersTable);

    int id = -1;
    (void) helper.GetFirstColumnValue(id);

    if (id > -1)
    {
        ClickedLeft(id);
    }
    else if (selectionRight > -1)
    {
        ClickedRight(selectionRight);
    }
}

void SelectionWindow::slotAccept()
{
    if ((ui.selectionList->count() >= mMinSize) && (ui.selectionList->count() <= mMaxSize))
    {
        accept();
    }
}

