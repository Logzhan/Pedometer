package com.geek.motion

import android.annotation.SuppressLint
import android.content.Context
import android.hardware.Sensor
import android.hardware.SensorEvent
import android.hardware.SensorEventListener
import android.hardware.SensorManager
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity(),SensorEventListener{
    private var sensorManager: SensorManager? = null
    private var sensor: Sensor? = null
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        initSensor()
        textView.text = stringFromJNI()

        pedometerInit()
    }

    private fun initSensor() {
        sensorManager = getSystemService(Context.SENSOR_SERVICE) as SensorManager
        sensor = sensorManager!!.getDefaultSensor(Sensor.TYPE_ACCELEROMETER)
        sensorManager?.registerListener(this, sensor, 100)
    }

    override fun onAccuracyChanged(sensor: Sensor?, accuracy: Int) {

    }
    @SuppressLint("SetTextI18n")
    override fun onSensorChanged(event: SensorEvent?) {
        val values = event?.values
        val x = values!![0]
        val y = values[1]
        val z = values[2]
        val step = pedometerUpdate(x, y, z)
        val str = "Step = $step"
        textView?.text = str
    }

    private external fun stringFromJNI(): String
    private external fun pedometerInit()
    private external fun pedometerUpdate(x:Float, y:Float, z:Float): Long
    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}