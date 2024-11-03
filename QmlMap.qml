import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15

Item {
    id: window
    width: 640
    height: 480

    Component {
        id: locmarker
        MapQuickItem {
            id:mark_gen
            property color markerColor: "lightgray"
            property var position
            property var size: mapview.zoomLevel
            anchorPoint.x: 10
            anchorPoint.y: 10
            coordinate: position
            sourceItem: Rectangle {
                width: mark_gen.size
                height: mark_gen.size
                color: mark_gen.markerColor
                radius: 10
                border.color: "black"
                border.width: 2
            }
        }
    }

    /********************************************************** Slot define start ********************************************************/

    property var markerList: []

    function addNewMark(lat, lon, color) {
        mapview.center = QtPositioning.coordinate(lat, lon);
        var item = locmarker.createObject(window, {coordinate:QtPositioning.coordinate(lat, lon), markerColor:color})
        console.log("Add new mark at lat", lat, "lon", lon, "color", color);
        markerList.push(item);
        mapview.addMapItem(item)
    }

    function removeMark(index) {
        if (index >= 0 && index < markerList.length) {
            mapview.removeMapItem(markerList[index]);
            markerList.splice(index, 1);
            console.log("Marker at index", index, "removed");
        } else {
            console.log("Invalid index:", index);
        }
    }

    function changeMarkColor(index, color) {
        if (index >= 0 && index < markerList.length) {
            console.log("Mark at", index, "change color to", color);
            markerList[index].markerColor = color;
        } else {
            console.log("Invalid index:", index);
        }
    }


    function removeAllMark() {
        console.log("testFunction remove case from C++");

        for (var i = 0; i < markerList.length; i++) {
            mapview.removeMapItem(markerList[i]); // Xóa từng marker khỏi mapview
        }
        markerList = []; // Dọn sạch mảng markers
    }

    function moveMapCenterTo(lat, lon) {
        mapview.center = QtPositioning.coordinate(lat, lon);
    }

    /********************************************************** Slot define end ********************************************************/


    Plugin {
        id: osmPlugin
        name: "osm"
        PluginParameter {
            name: "osm.mapping.custom.host"
            value: "https://tile.openstreetmap.org/"
        }
    }

    Map {
        id: mapview
        anchors.fill: parent
        plugin: osmPlugin
        center: QtPositioning.coordinate(21.037567751217743, 105.78886850880606) // Hà Nội
        zoomLevel: 15
        activeMapType: mapview.supportedMapTypes[mapview.supportedMapTypes.length - 1]

        Component.onCompleted: {
            console.log("Loaded map success");
        }

        MouseArea {
            property real startX
            property real startY
            anchors.fill: parent
            onWheel: function(event) {
                if (event.angleDelta.y < 0) {
                    mapview.zoomLevel -= 0.25;
                } else {
                    mapview.zoomLevel += 0.25;
                }

                for (var i = 0; i < markerList.length; i++) {
                    markerList[i].size = mapview.zoomLevel
                }

                event.accepted = true;
            }

            onPressed: function(event) {
                startX = event.x;
                startY = event.y;
            }

            onPositionChanged: function(event) {
                var dx = event.x - startX;
                var dy = event.y - startY;
                var multipler = 50000 / Math.pow(mapview.zoomLevel, 8);
                var newCenter = QtPositioning.coordinate(
                    mapview.center.latitude + (dy * multipler),
                    mapview.center.longitude - (dx * multipler)
                );
                mapview.center = newCenter;
                startX = event.x;
                startY = event.y;
            }
        }
    }
}
