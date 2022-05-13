# CustomParcel

通过手写Parcel加深理解Android Parcelable序列化原理

只实现了实现了部分数据类型序列化，如 `int`、`char`、`String`

使用方法：

```kotlin
val parcel = CustomParcel()
//写之前必须重置position
parcel.setDataPosition(0)
parcel.writeInt(99)
parcel.writeChar('A')
parcel.writeString("jack/aimee")
parcel.writeInt(88)
parcel.writeChar('B')

//读之前必须重置position
parcel.setDataPosition(0)
//这里需要注意，读的顺序必须和写的顺序一致，否则会获取数据异常
val text = parcel.readInt().toString() + "\n" +
           parcel.readChar() + "\n" +
           parcel.readString() + "\n" +
           parcel.readInt().toString() + "\n" +
           parcel.readChar()
```

