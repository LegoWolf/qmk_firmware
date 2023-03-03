import json, sys
from pprint import pprint

params = {}
with open(sys.argv[1], "r") as file:
	params = json.loads(file.read())

def listReplace(items, replacements):
	current = ["" if isinstance(x, int) else x for x in items]
	for find, replace in replacements.items():
		current = [replace if x == find else x.encode("utf-8") for x in current]
	return current

def tidyKeys(keys):
	return listReplace(keys, {"KC_TRNS": "_______", "KC_NO": "XXXXXXX"})

def convertLayouts(layouts):
	newlayouts = []
	for layout in layouts:
		numrows = len(layout) / 2
		converted = []
		for i in range(numrows):
			left = tidyKeys(layout[i])
			right = tidyKeys(list(reversed(layout[i + numrows])))
			row = [left, right]
			converted.append(row)
		newlayouts.append(converted)
	return newlayouts   

def getSeparator(widths, prevrow, nextrow):
	def full(row, index):
		return 1 if (row[index] != "" if row is not None and 0 <= index and index < len(row) else False) else 0

	def getCross(prevrow, nextrow, index):
		tl, tr = full(prevrow, index), full(prevrow, index + 1)
		bl, br = full(nextrow, index), full(nextrow, index + 1)
		if (tl + tr + bl + br >= 3) or (tl + bl == 2) or (tr + br == 2):
			return "|"
		elif ((br == 1) and (tl + tr + bl == 0)) or ((tl == 1) and (tr + bl + br == 0)):
			return ","
		elif (tr == 1) and (tl + bl + br == 0):
			return "`"
		elif (bl == 1) and (tl + tr + br == 0):
			return "."
		else:
			return "+"

	started = False
 	separator = " "
	for i in range(len(widths)):
		if (prevrow is not None and prevrow[i] != "") or (nextrow is not None and nextrow[i] != ""):
			if not started:
				separator = separator[:-1] + getCross(prevrow, nextrow, i - 1)
				started = True
			separator += "-" * (widths[i] + 2) + getCross(prevrow, nextrow, i)
		else:
			separator += " " * (widths[i] + 3)
	return separator

def getWidths(layouts, index):
	widths = [0] * len(layouts[0][0][index])
	for layout in layouts:
		for row in layout:
			for i in range(len(widths)):
				widths[i] = max(widths[i], len(row[index][i]) + 1)
	return widths

def getKeys(widths, row):
	keys = "  "
	for i in range(len(row)):
		key = row[i] + "," if row[i] != "" else row[i]
		keys += key.ljust(widths[i]) + "   "
	return keys[:-1]

def formatLayouts(layouts):
	leftwidths = getWidths(layouts, 0)
	rightwidths = getWidths(layouts, 1)
	output = ""

	for li in range(len(layouts)):
		layout = layouts[li]
		output += "  [%d] = LAYOUT_split_3x6_3(\n" % li
		prevleft = prevright = None
		for ri in range(len(layout)):
			row = layout[ri]
			output += "  //" + getSeparator(leftwidths, prevleft, row[0]) + "  " + getSeparator(rightwidths, prevright, row[1]) + "\n"
			rightkeys = getKeys(rightwidths, row[1]).rstrip()
			if ri == len(layout) - 1:
				rightkeys = rightkeys[:-1]
			output += "    " + getKeys(leftwidths, row[0]) + "  " + rightkeys + "\n"
			prevleft, prevright = row[0], row[1]
		output += "  //" + getSeparator(leftwidths, prevleft, None) + "  " + getSeparator(rightwidths, prevright, None) + "\n"
		output += "  )%s\n\n" % ("," if li < len(layouts) - 1 else "")
	return output

layouts = params.get("layout", {})
newlayouts = convertLayouts(layouts)
print(formatLayouts(newlayouts))
