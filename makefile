#Executable
EXECUTABLE=HelloWorld

#Sources
SOURCES=HelloWorld.m src/OGTK.m src/OGTKBase.m src/OGTKTypeWrapper.m src/OGTKBaseBuilder.m src/OGTKCallbackData.m src/OGTKSignalConnector.m src/OGTKSignalData.m src/OGTKAboutDialog.m src/OGTKAccelLabel.m src/OGTKActionBar.m src/OGTKAlignment.m src/OGTKAppChooserButton.m src/OGTKAppChooserDialog.m src/OGTKAppChooserWidget.m src/OGTKApplicationWindow.m src/OGTKArrow.m src/OGTKAspectFrame.m src/OGTKAssistant.m src/OGTKBin.m src/OGTKBox.m src/OGTKBuilder.m src/OGTKButtonBox.m src/OGTKButton.m src/OGTKCalendar.m src/OGTKCellView.m src/OGTKCheckButton.m src/OGTKCheckMenuItem.m src/OGTKColorButton.m src/OGTKColorChooserDialog.m src/OGTKColorChooserWidget.m src/OGTKColorSelectionDialog.m src/OGTKColorSelection.m src/OGTKComboBox.m src/OGTKComboBoxText.m src/OGTKContainer.m src/OGTKDialog.m src/OGTKDrawingArea.m src/OGTKEntry.m src/OGTKEventBox.m src/OGTKExpander.m src/OGTKFileChooserButton.m src/OGTKFileChooserDialog.m src/OGTKFileChooserWidget.m src/OGTKFixed.m src/OGTKFlowBox.m src/OGTKFlowBoxChild.m src/OGTKFontButton.m src/OGTKFontChooserDialog.m src/OGTKFontChooserWidget.m src/OGTKFontSelectionDialog.m src/OGTKFontSelection.m src/OGTKFrame.m src/OGTKGLArea.m src/OGTKGrid.m src/OGTKHandleBox.m src/OGTKHBox.m src/OGTKHButtonBox.m src/OGTKHeaderBar.m src/OGTKHPaned.m src/OGTKHScale.m src/OGTKHScrollbar.m src/OGTKHSeparator.m src/OGTKHSV.m src/OGTKIconView.m src/OGTKImage.m src/OGTKImageMenuItem.m src/OGTKInfoBar.m src/OGTKInvisible.m src/OGTKLabel.m src/OGTKLayout.m src/OGTKLevelBar.m src/OGTKLinkButton.m src/OGTKListBox.m src/OGTKListBoxRow.m src/OGTKLockButton.m src/OGTKMenuBar.m src/OGTKMenuButton.m src/OGTKMenuItem.m src/OGTKMenu.m src/OGTKMenuShell.m src/OGTKMenuToolButton.m src/OGTKMessageDialog.m src/OGTKMisc.m src/OGTKModelButton.m src/OGTKNativeDialog.m src/OGTKNotebook.m src/OGTKOffscreenWindow.m src/OGTKOverlay.m src/OGTKPaned.m src/OGTKPlacesSidebar.m src/OGTKPopover.m src/OGTKPopoverMenu.m src/OGTKProgressBar.m src/OGTKRadioButton.m src/OGTKRadioMenuItem.m src/OGTKRadioToolButton.m src/OGTKRange.m src/OGTKRecentChooserDialog.m src/OGTKRecentChooserMenu.m src/OGTKRecentChooserWidget.m src/OGTKRevealer.m src/OGTKScaleButton.m src/OGTKScale.m src/OGTKScrollbar.m src/OGTKScrolledWindow.m src/OGTKSearchBar.m src/OGTKSearchEntry.m src/OGTKSeparator.m src/OGTKSeparatorMenuItem.m src/OGTKSeparatorToolItem.m src/OGTKShortcutsShortcut.m src/OGTKSpinButton.m src/OGTKSpinner.m src/OGTKStack.m src/OGTKStackSidebar.m src/OGTKStackSwitcher.m src/OGTKStatusbar.m src/OGTKSwitch.m src/OGTKTable.m src/OGTKTearoffMenuItem.m src/OGTKTextView.m src/OGTKToggleButton.m src/OGTKToggleToolButton.m src/OGTKToolbar.m src/OGTKToolButton.m src/OGTKToolItemGroup.m src/OGTKToolItem.m src/OGTKToolPalette.m src/OGTKTreeView.m src/OGTKVBox.m src/OGTKVButtonBox.m src/OGTKViewport.m src/OGTKVolumeButton.m src/OGTKVPaned.m src/OGTKVScale.m src/OGTKVScrollbar.m src/OGTKVSeparator.m src/OGTKWidget.m src/OGTKWindow.m

#Objects
OBJECTS=$(SOURCES:.m=.o)

#compiler
CC=clang

#CFLAGS
CFLAGS=`objfw-config --cppflags` `pkg-config --cflags gtk+-3.0` -g -O0 -c -Wno-deprecated-declarations -Wno-deprecated

#Objective-c specific flags
OBJCFLAGS=`objfw-config --objcflags`

#Objective-c specific flags
MACOBJCFLAGS=$(OBJCFLAGS)

#GTK dependencies
GTKDEPS=`pkg-config --libs gtk+-3.0`

#Common flags
COMMONFLAGS=$(CFLAGS) $(OBJCFLAGS)

LIBS=`objfw-config --rpath --libs` $(GTKDEPS)

#Targets

#Linux Target
linux: all

#Mac Target
mac: COMMONFLAGS=$(MACOBJCFLAGS) $(GTKDEPS)
mac: all

#Windows Target
windows: all

#All Target
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

%.o: %.m
	$(CC) $(COMMONFLAGS) $< -o $@

clean: 
	rm -rf *.o *.d $(EXECUTABLE)
	rm -rf src/*.o src/*.d $(EXECUTABLE)
