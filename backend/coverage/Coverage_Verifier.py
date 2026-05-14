import xml.etree.ElementTree as ET
from typing import Final

MINIMUM_COVERAGE: Final = 70

tree = ET.parse('coverage.xml')
root = tree.getroot()

lines_covered = int(root.attrib['lines-covered'])
lines_valid = int(root.attrib['lines-valid'])

actual_coverage = (lines_covered / lines_valid) * 100

if actual_coverage > MINIMUM_COVERAGE:
    print(f"Mesuared Coverage is {actual_coverage:.0f}, and is higher than {MINIMUM_COVERAGE}")
else:
    raise ValueError(f"Mesuared Coverage is {actual_coverage:.0f}, and is lower than {MINIMUM_COVERAGE}")