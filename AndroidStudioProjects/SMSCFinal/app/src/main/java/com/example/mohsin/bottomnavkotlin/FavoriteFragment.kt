package com.example.mohsin.bottomnavkotlin


import android.content.Intent
import android.os.Bundle
import android.provider.AlarmClock
import android.support.v4.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import kotlinx.android.synthetic.main.fragment_medication.*


// TODO: Rename parameter arguments, choose names that match
// the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
private const val ARG_PARAM1 = "param1"
private const val ARG_PARAM2 = "param2"

/**
 * A simple [Fragment] subclass.
 *
 */
class FavoriteFragment : Fragment() {




    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_medication, container, false)



        /**Set_alarm.setOnClickListener{

            val intent = Intent(AlarmClock.ACTION_SET_ALARM)

            intent.putExtra(AlarmClock.EXTRA_MESSAGE,"My new Alarm")
            intent.putExtra(AlarmClock.EXTRA_HOUR, 10)
            intent.putExtra(AlarmClock.EXTRA_MINUTES, 32)
            intent.putExtra(AlarmClock.EXTRA_DAYS, arrayListOf(2,3,4))

            startActivity(intent)

        }*/




    }


}
