package com.jk.parcel

import android.annotation.SuppressLint
import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import com.jk.parcel.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    @SuppressLint("SetTextI18n")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        val parcel = CustomParcel()

        parcel.setDataPosition(0)
        parcel.writeInt(99)
        parcel.writeChar('A')
        parcel.writeString("jack/aimee")
        parcel.writeInt(88)
        parcel.writeChar('B')

        parcel.setDataPosition(0)
        Log.e("jack", "---------------------------")
        binding.sampleText.text = parcel.readInt().toString() + "\n" +
                parcel.readChar() + "\n" +
                parcel.readString() + "\n" +
                parcel.readInt().toString() + "\n" +
                parcel.readChar()

        Log.e("jack", binding.sampleText.text.toString())
    }
}